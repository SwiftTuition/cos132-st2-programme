---
title: Unit G Test #3 Memo
assessment: Unit G Test #3 (ST2 Programme)
totalMarks: 25
style: g3
tex: unit_g_test_3_memo.tex
pdf: unit_g_test_3_memo.pdf
compiler: xelatex
---

# COS 132 — Unit G Test #3 — Memo

Good day, good people. Below is the worked solution for Unit G Test #3 — the hardest of the Unit G bank, calibrated to exam-realistic ST2 difficulty. Read the reasoning, not just the answers.

**Total marks:** 25

---

## Question 1 [8 marks]

### (a) True or False

**i. True.** [1 mark]

In mutual recursion, function `A` calls `B` and `B` calls `A`. The C++ compiler reads source code top-down and needs to know about every function it sees called, before that call appears. If you write `A`'s body first and `A` calls `B`, the compiler does not yet know `B` exists.

The fix is to declare both prototypes up front:

```cpp
bool isEven(int n);   // prototype: tells compiler "this exists, signature is...";
bool isOdd(int n);    // prototype

bool isEven(int n) {
    if (n == 0) return true;
    return isOdd(n - 1);    // OK: compiler already saw the prototype above
}

bool isOdd(int n) {
    if (n == 0) return false;
    return isEven(n - 1);
}
```

Without those two prototype lines at the top, the compiler chokes when `isEven` calls `isOdd`, because it has not yet seen `isOdd`'s declaration.

For ordinary direct recursion, no prototype is needed — the function's own header is already visible inside its own body. The prototype trick is what makes mutual recursion possible.

---

**ii. False.** [1 mark]

A function without a base case **compiles fine**. The compiler does not analyse whether your recursion will terminate; that's a runtime concern. The function would call itself again and again, each call adding a frame to the runtime stack. Eventually the stack runs out of space and the operating system terminates the program with a "stack overflow" error. That is a **runtime** error, not a compile-time error.

This is a useful distinction. Compile-time errors are about syntax and types. Runtime errors are about what actually happens when the program runs. C++ is permissive about runtime issues — the compiler trusts you to write terminating recursion.

---

**iii. True.** [1 mark]

The Search plan (Plan I) is built around a flag. The flag starts `false`, meaning "not found yet." The loop continues while there are still values to check **and** the flag is still `false`. The moment the target is found, the flag flips to `true`, and the loop exits on its next condition check.

```cpp
bool found = false;
while (!found && stillHaveValues) {
    cin >> value;
    if (value == target) {
        found = true;
    }
}
```

The double condition `!found && stillHaveValues` is what makes Plan I efficient — it stops as soon as the match is found, rather than continuing to scan after.

---

**iv. True.** [1 mark]

`for (;;)` and `while (true)` are equivalent for the compiler. Both produce a loop that never exits naturally; you would need a `break` or `return` to stop it.

Both are valid C++ and both have a long history in real code. Style guides differ on which to prefer. The reason many guides (including Google's C++ Style Guide) recommend `while (true)` is clarity of intent: `while (true)` reads as "keep looping forever," while `for (;;)` invites a reader to ask "wait, what is the condition? Where is the update?" before realising it is supposed to be infinite.

If the question asked which is *strictly correct*, both would be. The question asks about idiomatic style, where `while (true)` is the more common modern recommendation.

---

### (b) Multiple choice

**i. B.** `3 2 1 `. [1 mark]

Trace `f(3)`:

- `n = 3`, not `<= 0`, so print `3 `, then call `f(2)`.
  - `n = 2`, print `2 `, call `f(1)`.
    - `n = 1`, print `1 `, call `f(0)`.
      - `n = 0`, return immediately (base case).
    - back from `f(0)`. No more code in this stack frame, return.
  - back from `f(1)`, return.
- back from `f(2)`, return.

Output: `3 2 1 ` (with trailing space).

The function prints the value **before** the recursive call. So the first thing printed is `n` itself, then the recursion handles the smaller values. That gives the descending order.

> If you got `1 2 3 `, you assumed the printing happened after the recursive call (post-order). It does not — the print is before. Q2 of this paper tests the harder case where printing happens both before AND after.

---

**ii. D.** Plan I (Search). [1 mark]

The keyword in the scenario is "stops as soon as the target is found." That is the unique feature of Plan I — it walks the values with a flag, and once the flag flips to `true`, the loop exits early.

The other plans either keep scanning the whole list (Plan E counts everything that matches; Plan G needs to confirm no later value is bigger) or do not address searching at all (Plan A is for known counts).

---

**iii. C.** Stack overflow. [1 mark]

Same idea as Q1(a)(ii). C++ compiles the program — the compiler does not know the recursion will not terminate. At runtime, each recursive call adds a frame to the stack. Eventually the stack runs out, the OS notices, and it terminates the program with an error.

The other options:
- **A** wrong — the compiler does not analyse termination.
- **B** wrong — C++ functions do not have a "default return value." If the function does not reach a `return`, behaviour is undefined.
- **D** wrong — the function never returns, because each call leads to another call.

---

**iv. B.** [1 mark]

This is the only option that has all three required pieces:

1. **Both prototypes declared first** (`bool isEven(int n);` and `bool isOdd(int n);`).
2. **Each function calls the other** (mutual recursion, not self-recursion).
3. **Each function has a correct base case** (returns `true` for `isEven(0)`, returns `false` for `isOdd(0)`).

Why the others fail:
- **A** — both functions call themselves, not each other. That is direct recursion, and it is logically wrong: `isEven(5)` calling `isEven(4)` and so on never tells you anything about even-ness; it just decrements until reaching `0` and returns `true` regardless of whether the original number was even.
- **C** — no base case. Both functions recurse forever, regardless of input.
- **D** — the recursive case is missing a `return`. The function calls `isOdd(n - 1)` but does not return its result. Behaviour is undefined.

---

## Question 2 [7 marks]

### (a) Bidirectional recursion trace [4 marks]

Output: `3 2 1 1 2 3 `

The function prints `n` **twice**: once before the recursive call, once after. So each level of the recursion contributes its `n` to the output on the way down **and** on the way up.

Trace `mystery(3)`:

- Enter `mystery(3)`. Print `3 `. Call `mystery(2)`.
  - Enter `mystery(2)`. Print `2 `. Call `mystery(1)`.
    - Enter `mystery(1)`. Print `1 `. Call `mystery(0)`.
      - Enter `mystery(0)`. Base case, return.
    - Back from `mystery(0)`. Print `1 `. Return.
  - Back from `mystery(1)`. Print `2 `. Return.
- Back from `mystery(2)`. Print `3 `. Return.

The output sequence is: `3 2 1` (going down into the recursion), then `1 2 3` (coming back up). Concatenated: `3 2 1 1 2 3 ` with trailing space.

### Marks breakdown

- 1 mark per correct value in the descending part (`3 2 1`).
- 1 mark for the symmetric ascending part (`1 2 3`).

### Common pitfalls

- Writing only `3 2 1 `. You missed the post-recursive `cout`.
- Writing `1 2 3 1 2 3 ` (ascending then ascending). You missed that the first half is descending.
- Writing `3 3 2 2 1 1 ` (each value twice in succession). You missed the recursive call between the two prints.

The mental model: the recursive call sits **between** the two `cout`s. Each call goes "print, recurse all the way down, on return print again." The recursion is what separates the two prints.

---

### (b) Find the bug [3 marks]

**(i) What the function actually does** [1 mark]

The function (in its buggy form) computes a strange sum involving repeated truncating divisions of `n`. For `n = 123`, it returns `13` instead of the expected digit sum `6`. It does not actually sum the digits of `n`.

If you wanted to be precise: the buggy function returns the sum of `n / 10`, plus `(n / 10) / 10`, plus `((n / 10) / 10) / 10`, and so on, all the way down to `0`. So for `123`: `12 + 1 + 0 = 13`.

### (ii) The bug and the fix [2 marks]

The bug is on the line:

```cpp
return (n / 10) + sumDigits(n / 10);
```

The first `n / 10` should be `n % 10`. The intention is "extract the last digit (`n % 10`) and add it to the digit sum of everything else (`sumDigits(n / 10)`)." The buggy version uses `n / 10` for both parts, which means it never extracts a digit; it just keeps shifting `n` right and summing the shifted values.

Corrected line:

```cpp
return (n % 10) + sumDigits(n / 10);
```

### Mark allocation

- 1 mark for identifying the line as the buggy one.
- 1 mark for writing the corrected version with the right operator on the right side.

### How to spot the bug

The two operators (`%` and `/`) do related but different things on integers:

- `n % 10` extracts the **last digit** of `n` (the remainder after dividing by 10).
- `n / 10` truncates `n` by dropping its last digit (integer division).

Both are useful in `sumDigits`, but they have specific roles: `%` is for "what is the last digit?", `/` is for "everything except the last digit." Using `/` where you wanted `%` means you are summing the wrong piece each level.

### Trace of the corrected version (sanity check)

`sumDigits(123)`:
- `n = 123`, not `0`. Return `123 % 10 + sumDigits(123 / 10) = 3 + sumDigits(12)`.
- `sumDigits(12)` returns `12 % 10 + sumDigits(12 / 10) = 2 + sumDigits(1)`.
- `sumDigits(1)` returns `1 % 10 + sumDigits(1 / 10) = 1 + sumDigits(0)`.
- `sumDigits(0)` returns `0` (base case).

Unwind: `1 + 0 = 1`, then `2 + 1 = 3`, then `3 + 3 = 6`. Correct.

---

## Question 3 [5 marks]

### (a) Base case [1 mark]

The base case is when `:N = 0`. The procedure executes `STOP`, which ends the current call without doing anything more. In Logo terms: the procedure has nothing more to print or recurse on once `:N` reaches `0`.

### (b) C++ implementation [3 marks]

```cpp
void countdown(int n) {
    if (n == 0) {
        return;
    }
    cout << n << endl;
    countdown(n - 1);
}
```

### How to think about it

The Logo procedure has three parts:

1. A base case: `IF :N = 0 [STOP]` — the recursion ends when `:N` reaches `0`.
2. An action: `PRINT :N` — print the current value.
3. A recursive call: `COUNTDOWN :N - 1` — call the procedure on a smaller version of the input.

The C++ translation maps each part directly:

1. `IF :N = 0 [STOP]` becomes `if (n == 0) return;`. The Logo `STOP` is the equivalent of `return;` — it ends the current call.
2. `PRINT :N` becomes `cout << n << endl;`.
3. `COUNTDOWN :N - 1` becomes `countdown(n - 1);` (one recursive call with `n - 1` as the argument).

Notice that **no loop** appears anywhere. The procedure's repetition comes from the recursion itself — each call handles one value, then recurses on a smaller value. No `for`, no `while`. That is what "use direct recursion, not a loop" means.

### Marks breakdown

- 1 mark: function signature `void countdown(int n)`.
- 1 mark: correct base case (`if (n == 0) return;`).
- 1 mark: correct recursive case (print, then recurse with `n - 1`).

### Acceptable alternatives

`if (n <= 0) return;` is also fine. It handles negative inputs gracefully (if a user calls `countdown(-3)`, it just exits instead of recursing forever).

`if (n != 0) { cout << n << endl; countdown(n - 1); }` (positive form, no early `return`) is equivalent and earns full marks.

### Common pitfalls

- **Using a loop.** A `for` or `while` loop produces the right output, but the question explicitly says "use direct recursion, not a loop." Loop versions earn 0 marks for part (b).
- **Wrong order.** Calling `countdown(n - 1)` **before** the `cout` reverses the output (it would print `1 2 3` instead of `3 2 1`). The order matters: print first, recurse second.
- **Off-by-one.** Using `n - 1` is correct. Using `n` (no decrement) causes infinite recursion. Using `n - 2` skips every other value.
- **Forgetting the `return` in the base case.** Without `return`, the function falls through into the recursive call with `n = 0`, then `n = -1`, then `n = -2`, and so on forever (until stack overflow).

---

### (c) Output of `COUNTDOWN 3` [1 mark]

```
3
2
1
```

Each value on its own line (because `PRINT` in Logo, like `endl` in C++, ends the line).

Trace:
- `COUNTDOWN 3`: `:N` is `3`, not `0`. Print `3`, then `COUNTDOWN 2`.
- `COUNTDOWN 2`: print `2`, then `COUNTDOWN 1`.
- `COUNTDOWN 1`: print `1`, then `COUNTDOWN 0`.
- `COUNTDOWN 0`: base case, `STOP`. Nothing printed.

Output: `3`, `2`, `1`, each on its own line.

---

## Question 4 [5 marks]

### Expected answer

```cpp
void analyseMarks(int n) {
    int count = 0;
    int total = 0;
    int mark;
    for (int i = 0; i < n; i++) {
        cin >> mark;
        total = total + mark;
        if (mark > 50) {
            count++;
        }
    }
    double average = static_cast<double>(total) / n;
    cout << "Passing: " << count << endl;
    cout << "Average: " << average << endl;
}
```

### How to think about it

The spec describes four things the function has to do. Match each one to a plan from L17:

1. "Read exactly `n` integer marks" — Plan A (known count). A `for` loop running `n` times.
2. "Count how many are strictly greater than 50" — Plan E (conditional count). Initialise a counter to `0`, increment inside the loop only when the condition holds.
3. "Accumulate the total of all marks" — Plan F (accumulate). Initialise a running total to `0`, add each mark inside the loop.
4. "Print the count of passing marks and the average" — print after the loop, using a type cast for the average.

The whole function fits into one `for` loop (Plan A) with two pieces of work happening inside it (Plans E and F running side by side). After the loop, you compute the average and print the report.

### Marks breakdown

- 1 mark: function signature `void analyseMarks(int n)`.
- 1 mark: loop reads exactly `n` values from `cin` (`for` loop iterating `n` times, with `cin >> mark` inside).
- 1 mark: counter incremented only when `mark > 50`.
- 1 mark: total accumulated correctly (`total = total + mark` inside the loop, started at `0` outside).
- 1 mark: average computed as a `double` (with a cast to avoid integer division) and the output format is correct.

### Acceptable alternatives

The cast can take several equivalent forms:
- `static_cast<double>(total) / n` (preferred — explicit and modern C++).
- `(double)(total) / n` (C-style cast, valid but less idiomatic).
- `total / static_cast<double>(n)` (cast the divisor instead).
- `total * 1.0 / n` (multiply by `1.0` to force floating-point context).

All four earn full marks.

A `while` loop variant is fine, as long as it iterates the right number of times.

Using `>=` 51 instead of `>` 50 produces the same set (because marks are integers), but is strictly equivalent only if you can guarantee no fractional marks. Use `>` 50 to match the spec exactly.

### Common pitfalls

- **Forgetting the type cast.** `double average = total / n;` does integer division because both `total` and `n` are `int`. The fractional part is lost before the assignment to `double` happens. Test the function with `total = 75, n = 2` to spot it: with the cast you get `37.5`; without you get `37`.
- **Incrementing for `>= 50` instead of `> 50`.** The spec says "strictly greater than 50." A mark of exactly `50` does not pass.
- **Reading marks before declaring `total` and `count`.** They need to be declared and initialised before the loop, otherwise they hold garbage values from memory.

---

## After this test

This was the hardest Unit G test — calibrated to exam-realistic ST2 difficulty. Roughly:

- **22–25 marks:** Unit G is solid. You are ready for Unit H next week.
- **17–21 marks:** mostly there, but specific topics (mutual recursion, bidirectional traces, plan composition under spec pressure) need tightening. Replay the relevant lecture sections and try this paper again in a few days.
- **12–16 marks:** real gaps. Retry Unit G #1 and #2 first, then come back here.
- **Below 12:** retake Foundations Test #3, Unit G #1, and Unit G #2 in order. Build the foundation before tackling the synthesis.

### Logo coverage

This test contained one Logo→C++ conversion (Q3) — a recursive Logo procedure that must be translated to a recursive C++ function. A COS 132 lecturer recently confirmed (via a student in the group) that Logo→C++ conversions are examinable in ST2. This question represents the harder end of what you might see, where the Logo source uses recursion (not just `REPEAT`) and the C++ answer must mirror that structure.
