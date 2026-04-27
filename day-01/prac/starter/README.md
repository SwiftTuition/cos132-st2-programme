# Practical 1: The Study Squad Tracker

Good day, good people. This is the starter folder for **Practical 1** of Swift Tuition's ST2 Programme.

For the full specification (the formal practical brief), open `prac.md` (or `prac.pdf` if it's been rendered) in the parent folder.

For a step-by-step walkthrough of the solution, open `memo.md` in the parent folder. **Only read it after you've made an honest attempt.**

---

## Files in this folder

| File | What it is | Edit it? |
|---|---|---|
| `Squad.h` | The header file. Declares the namespace, the global variables, and every function signature. | NO |
| `Squad.cpp` | The implementation file. Contains stubs for every function. **This is where you write your code.** | YES |
| `main.cpp` | The test harness. Reads a test ID from stdin, calls the right function in your `Squad` namespace, and prints the result. | NO |
| `Makefile` | Build configuration. Tells `make` how to compile your code. | NO |
| `grade.sh` | The grading script. Compiles + runs all tests + prints a pass/fail report with marks. | NO |
| `tests/inputs/*.txt` | Input files for each test case. | NO |
| `tests/expected/*.txt` | Expected output for each test case. | NO |

The test files are visible by design. There's no point hiding them in a self-paced practice practical, and reading them helps you understand what each function should do.

---

## How to use this practical

### 1. Open in GitHub Codespaces

If you're working from the Swift Tuition repo on GitHub:

- Go to the repo
- Click the green **Code** button
- Click the **Codespaces** tab
- Click **Create codespace on main**

After about 30 seconds, you'll be in a browser-based VS Code with the C++ compiler already installed and ready to go.

### 2. Edit `Squad.cpp`

The functions all start with `// TODO` comments and a placeholder return value. Replace each `// TODO` with the actual implementation, following the spec in `prac.md`.

You only need to edit `Squad.cpp`. Do not touch `Squad.h` or `main.cpp` -- the grader uses the original versions.

### 3. Compile

Two ways:

**Using `make`:**
```
make
```
This produces an executable called `squad` in the current folder.

**Manually:**
```
g++ -std=c++98 -Wall -Wextra -pedantic -o squad main.cpp Squad.cpp
```

If your code has compilation errors, the compiler will tell you which line and what's wrong. Fix the errors before moving on.

### 4. Run the grader

```
./grade.sh
```

This compiles your code, runs every test, and prints a report like this:

```
================================================================
  Swift Tuition - Practical 1: The Study Squad Tracker
================================================================

Compiling...
  Compilation: OK

  [PASS] Test  1: addHours: basic                          3/3  marks
  [PASS] Test  2: incrementSessions: basic                 3/3  marks
  [PASS] Test  3: calculateAverage: normal                 5/5  marks
  [FAIL] Test  4: calculateAverage: divide-by-zero          0/5  marks
         Expected:
           0
         Got:
           inf
  [PASS] Test  5: scaleHours: integer-result               5/5  marks
  ...

================================================================
  Total:  62 / 65 marks (95%)
  Passed: 12 / 13 tests
================================================================
```

When a test fails, the grader shows you the first few lines of the expected output and the first few lines of what your program actually produced. Compare them carefully -- usually the difference is a missing space, a wrong number, or an off-by-one.

### 5. Iterate

Edit `Squad.cpp`, run `./grade.sh` again, repeat until everything passes. There is no penalty for running the grader many times. Run it as often as you want.

### 6. (Optional) Run the program manually

If you want to test specific cases by hand without going through the grader, you can run the binary directly. The program reads a test ID and the test inputs from stdin:

```
./squad
1
10 5
15
```

Or feed in an input file:

```
./squad < tests/inputs/01.txt
```

---

## Where to find help

| Stuck on... | Look at... |
|---|---|
| What a function is supposed to do | `prac.md` -- the formal specification |
| How to actually implement a function | `memo.md` -- the worked solution walkthrough (only after you've tried) |
| Why your code won't compile | The compiler's error message (read it carefully) |
| Why a test is failing | The `grade.sh` output -- look at "Expected" vs "Got" |
| C++ syntax in general | Your COS 132 Unit C-F lecture notes / study units |

---

## Tips

- **Run all commands from inside this `starter/` folder.** The Makefile, the grader, and the test paths all assume you're in here. From the parent folder you'd `cd starter` first.
- **Compile often.** Running `make` after every few changes catches small mistakes early. Don't write 200 lines and then try to compile.
- **Warnings about unused parameters are normal at first.** Until you implement a function body, the compiler complains that the parameters are unused. The warnings disappear as you fill the bodies in. They don't break the build.
- **Read the spec twice.** Especially for the report functions where exact spacing matters. Yolisa would be furious.
- **Start with the easy functions.** `addHours`, `incrementSessions`, `calculateAverage`, `scaleHours` are all one-liners. Do those first to build momentum.
- **Test by hand.** When a function feels unclear, run it manually with `./squad` and a test input. Watching what it actually prints often makes the spec click.
- **Don't skip the `count == 0` check** in `calculateAverage`. Dividing a `double` by zero gives `inf` or `nan`, which is what causes Test 4 to fail without the guard.
- **`grade.sh` writes a `grade-report.txt`** in the current folder each time you run it. It's a quick text summary of your latest score. Useful if you want to track progress.
- **If you're cloning this locally on Linux or macOS** and `./grade.sh` says "permission denied", run `chmod +x grade.sh` once and you're good. Codespaces handles permissions for you.

Good luck. Get to it.
