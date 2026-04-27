#!/usr/bin/env bash
# Swift Tuition grader for Practical 1: The Study Squad Tracker.
# Compiles your code, runs every test, prints a pass/fail report with marks.
# Run this as often as you like.

set -u

PRAC_NAME="Practical 1: The Study Squad Tracker"
BINARY="./squad"
TESTS_DIR="tests"

# Test definitions: id|name|marks
TEST_DEFS=(
    "1|addHours: basic|3"
    "2|incrementSessions: basic|3"
    "3|calculateAverage: normal|5"
    "4|calculateAverage: divide-by-zero|5"
    "5|scaleHours: integer-result|5"
    "6|isOnFire: at threshold|3"
    "7|isPassing: at threshold|3"
    "8|canTutor: both pass|6"
    "9|canTutor: average fails|6"
    "10|setReminder: single param|4"
    "11|setReminder: minutes unit|6"
    "12|printSessionLog: exact format|10"
    "13|processMember: Squad Star case|6"
    "14|isOnFire: below threshold|3"
    "15|isPassing: below threshold|3"
    "16|canTutor: sessions short|6"
    "17|setReminder: hours unit|4"
    "18|setReminder: 90 minutes truncation|5"
    "19|scaleHours: fractional result|5"
    "20|processMember: not a Squad Star|6"
)

echo "================================================================"
echo "  Swift Tuition - $PRAC_NAME"
echo "================================================================"
echo

# Compile. Prefer `make` (so students learn the Makefile workflow), but fall
# back to a direct g++ call if `make` is not on PATH.
echo "Compiling..."
if command -v make > /dev/null 2>&1; then
    BUILD_CMD="make squad"
else
    BUILD_CMD="g++ -std=c++98 -Wall -Wextra -pedantic -o squad main.cpp Squad.cpp"
fi

if $BUILD_CMD > /tmp/grade-build.log 2>&1; then
    echo "  Compilation: OK"
else
    echo "  Compilation: FAILED"
    echo
    cat /tmp/grade-build.log
    exit 1
fi
echo

# Run tests
total_passed=0
total_marks=0
earned_marks=0

for entry in "${TEST_DEFS[@]}"; do
    IFS='|' read -r tid name marks <<< "$entry"
    total_marks=$((total_marks + marks))

    input_file="$TESTS_DIR/inputs/$(printf '%02d' "$tid").txt"
    expected_file="$TESTS_DIR/expected/$(printf '%02d' "$tid").txt"

    if [ ! -f "$input_file" ] || [ ! -f "$expected_file" ]; then
        printf "  [SKIP] Test %2d: %-42s files missing\n" "$tid" "$name"
        continue
    fi

    # tr -d '\r' makes the comparison line-ending-agnostic so the grader
    # behaves the same whether your environment produces LF (Linux/Codespaces)
    # or CRLF (some Windows toolchains).
    actual=$("$BINARY" < "$input_file" 2>&1 | tr -d '\r')
    expected=$(tr -d '\r' < "$expected_file")

    if [ "$actual" = "$expected" ]; then
        printf "  [PASS] Test %2d: %-42s %2d/%-2d marks\n" "$tid" "$name" "$marks" "$marks"
        total_passed=$((total_passed + 1))
        earned_marks=$((earned_marks + marks))
    else
        printf "  [FAIL] Test %2d: %-42s  0/%-2d marks\n" "$tid" "$name" "$marks"
        printf "         Expected:\n"
        sed 's/^/           /' "$expected_file" | head -8
        printf "         Got:\n"
        echo "$actual" | sed 's/^/           /' | head -8
    fi
done

# Summary
total_tests=${#TEST_DEFS[@]}
total_failed=$((total_tests - total_passed))
if [ "$total_marks" -gt 0 ]; then
    percentage=$((100 * earned_marks / total_marks))
else
    percentage=0
fi

echo
echo "================================================================"
printf "  Total:  %d / %d marks (%d%%)\n" "$earned_marks" "$total_marks" "$percentage"
printf "  Passed: %d / %d tests\n" "$total_passed" "$total_tests"
echo "================================================================"

# Save a report file for reference
{
    echo "Practical 1 grade report"
    echo "Generated: $(date)"
    echo "Score: $earned_marks / $total_marks ($percentage%)"
    echo "Passed: $total_passed / $total_tests"
} > grade-report.txt

if [ "$total_failed" -gt 0 ]; then
    exit 1
fi
