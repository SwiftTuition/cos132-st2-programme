---
title: Unit G Test #1 Memo
assessment: Unit G Test #1 (ST2 Programme)
totalMarks: 22
style: g1
tex: unit_g_test_1_memo.tex
pdf: unit_g_test_1_memo.pdf
compiler: xelatex
---

# COS 132 — Unit G Test #1 — Memo

Good day, good people. Below is the worked solution for Unit G Test #1. Read the reasoning, not just the answers. The point of looking at a memo is to make the next question of this kind feel obvious instead of tricky.

**Total marks:** 22

---

## Question 1 [8 marks]

### (a) True or False

**i. True.** [1 mark]

The classic three-step swap uses a temporary variable as a holding pen. If you tried to do it in two steps without `temp`:

```cpp
a = b;   // a now holds b's value
b = a;   // b now holds a's value... but a is already b, so b is just b
```

You would lose the original value of `a` the moment you wrote into it. The temp keeps a copy safe so you can put it back into `b` after.

```cpp
int temp = a;   // remember a
a = b;          // a is now b
b = temp;       // b is now the remembered a
```

There are clever tricks that avoid `temp` (using XOR, or arithmetic identities like `a = a + b; b = a - b; a = a - b;`), but they are not what L17 teaches. The textbook plan is the temp-variable version.

---

**ii. True.** [1 mark]

This is the defining feature of `do-while`. The body sits between `do {` and `} while (...);`. The condition is checked **after** each iteration, not before. So even if the condition is false from the very start, the body has already run once by the time the check happens.

Compare:
- `for` and `while` — check condition before each iteration. If it is false on entry, body never runs.
- `do-while` — body runs first, then the condition decides whether to repeat.

This makes `do-while` the natural fit for input validation: ask the user something, then check whether their answer is valid; if not, ask again. You cannot check first because they have not given you an answer yet.

---

**iii. False.** [1 mark]

The Count plan initialises its counter to **`0`**, not `1`. The reason is simple: before any value has been seen, the count of "values that match the condition" is zero.

The pattern is:

```cpp
int count = 0;                  // start at zero
while (more values to read) {
    cin >> value;
    if (value matches some condition) {
        count++;                // bump only when condition is true
    }
}
```

Initialising to `1` would make every count one too high. A common student mistake.

---

**iv. True.** [1 mark]

Plan I (Search) is built around a boolean flag. The flag starts at `false`, meaning "I have not found it yet." The loop continues while there are still values to check **and** the flag is still `false`. The moment a match is found, the flag flips to `true`, which causes the loop to exit on its next condition check.

```cpp
bool found = false;
// loop while there are values left AND we have not found it yet
while (still has values && !found) {
    cin >> value;
    if (value == target) {
        found = true;       // flip the flag, loop exits next check
    }
}
```

The double condition is what makes Plan I efficient. Without `&& !found`, you would keep looping after the match, wasting work.

---

### (b) Multiple choice

**i. C.** Plan A combined with Plan F. [1 mark]

There are two things happening in the scenario, and they correspond to two different plans.

- "Read exactly 10 marks" is a **known count** of values, which is Plan A. It looks like `for (int i = 0; i < 10; i++) { cin >> mark; ... }`.
- "Accumulate their total" is a **running sum**, which is Plan F. It looks like `total = total + mark;` inside the loop.

Plan composition is the whole point of Lecture 17. Most real problems are not solved by one plan in isolation; they are solved by recognising that a problem is "Plan X driving the loop, Plan Y doing the work inside."

The wrong answers:
- A only ignores the accumulation work.
- B only ignores the loop structure.
- D is for finding the largest, not for summing.

---

**ii. C.** `do-while`. [1 mark]

Same reasoning as Q1(a)(ii). The `do-while` body runs first, then the condition is checked. Even if the condition is `false` on entry (which would prevent any iterations of `for` or `while`), `do-while` has already executed the body once before getting to the check.

---

**iii. D.** Plan I (Search). [1 mark]

The keyword in the scenario is "stops as soon as the target is found." That is exactly what Plan I does — it walks through the values with a flag, and the flag flipping to `true` ends the search early.

The wrong answers:
- A (Count) keeps counting through the whole list, even after finding matches. It does not stop early.
- F (Accumulate) keeps summing through the whole list. Same problem.
- G (Find largest) walks the whole list to be sure no later value is bigger. It cannot stop early.

Stopping early is the special trick that makes Search different from the others.

---

**iv. B.** `int temp = a; a = b; b = temp;`. [1 mark]

This is the textbook three-step swap from L17 Plan H.

The wrong answers tell you exactly what goes wrong if you try to skip the temp:
- **A** — `a = b; b = a;` overwrites `a` with `b`'s value, then writes that same value back into `b`. After the two lines, both variables hold what `b` originally held. You have lost the original `a`.
- **C** — `int temp = a; a = temp; b = a;` saves `a` into `temp`, then writes `temp` (the old `a`) back into `a` (a no-op), then copies `a` into `b`. So `b` now holds the original `a`, but `a` itself is unchanged. The two values have not been exchanged.
- **D** — `a, b = b, a;` is the Python or Ruby tuple-swap syntax. It does not work in C++. The comma there is the C++ comma operator, which evaluates the left side, throws the result away, and produces the right side as the value of the whole expression. So this line ends up as `b = a;`, which assigns `a` into `b` and loses `b`'s original value entirely. C++ has no built-in tuple-swap shortcut; you have to use the temp-variable approach.

---

## Question 2 [6 marks]

### (a) Output: `5 4 3 2 1 ` [2 marks]

A `for` loop with a counter going **down**. Trace it:

- `i = 5`: `5 >= 1` is true, print `5 `, then `i--` makes `i = 4`.
- `i = 4`: print `4 `, `i = 3`.
- `i = 3`: print `3 `, `i = 2`.
- `i = 2`: print `2 `, `i = 1`.
- `i = 1`: `1 >= 1` is true, print `1 `, `i = 0`.
- `i = 0`: `0 >= 1` is false. Exit.

Each value is followed by a space (because the `cout` prints `i << " "`), so the final output has a trailing space.

> Watch out: a common mistake is reading `i--` as "stop at 1" when actually `i--` decrements after the body runs. So `i = 1` does run (the condition was checked while `i` was still `1`). The loop only exits when `i` reaches `0`.

---

### (b) Output: `3` [2 marks]

This is the Sentinel plan (Plan C) plus the Count plan (Plan E) composed.

Trace with input `7 4 9 -1`:

- Read first value: `value = 7`. `7 != -1` is true, enter loop. `count = 1`. Read next: `value = 4`.
- Loop check: `4 != -1` true. `count = 2`. Read next: `value = 9`.
- Loop check: `9 != -1` true. `count = 3`. Read next: `value = -1`.
- Loop check: `-1 != -1` false. Exit.

Output: `3`. The sentinel itself is **not** counted, because the count is incremented before reading the next value.

> If you got `4`, you counted the sentinel. The trick of Plan C is that the loop reads the next value at the **end** of the body, then re-checks the condition. So the sentinel itself never gets processed.

---

### (c) Output: `10` [2 marks]

A `do-while` where the condition is `false` from the start. The whole point of this question.

Trace:
- Enter the `do` block. Print `x`, which is `10`. Then `x--` makes `x = 9`.
- Check condition: `9 > 10` is `false`. Exit.

Output: `10`. The body ran once (printing `10`), then the condition check failed and the loop ended.

> If you got nothing (no output), you treated `do-while` like `while`. They are different. `do-while` always runs its body at least once.
> If you got `109876...` (counting all the way down), you missed the condition entirely. The condition is `x > 10`, not `x > 0`.

---

## Question 3 [4 marks]

### (a) Expected answer [3 marks]

```cpp
void printNumbers(int n) {
    for (int i = 1; i <= n; i++) {
        cout << i << endl;
    }
}
```

### How to think about it

The Logo procedure does three things:

1. Takes one parameter (`:N`).
2. Sets up a counter `:I` starting at `1`.
3. Repeats `:N` times, printing `:I` and incrementing.

In C++, you do not need a separate counter variable. The `for` loop's own counter does the job. Start at `1`, run while `i <= n`, print each value, increment.

### Marks breakdown

- 1 mark: function signature `void printNumbers(int n)`.
- 1 mark: loop runs the right number of times (1 to n inclusive).
- 1 mark: prints each value on its own line.

### Other valid answers

A `while` loop is fine:

```cpp
void printNumbers(int n) {
    int i = 1;
    while (i <= n) {
        cout << i << endl;
        i++;
    }
}
```

Using `cout << i << "\n";` instead of `endl` is fine.

Mirroring the Logo source line-for-line (with an explicit auxiliary variable `i`) is also fine. The marker awards full credit if the output matches and the structure is sensible.

### (b) Plan A. [1 mark]

The Logo procedure repeats a **known number** of times (`:N` is given as a parameter, so you know exactly how many iterations you need). That is the definition of Plan A: read or process a known count of values.

> Common confusion: students sometimes pick Plan F (Accumulate) because they see the counter `:I` increasing. But Plan F is about a **running total** that survives across iterations and is reported at the end. Here `:I` is just the loop counter, not a sum being accumulated.

---

## Question 4 [4 marks]

### (a) Base case: when `n == 0`, return `0`. [1 mark]

The base case is the simplest input the function knows how to answer without making a recursive call. The piecewise definition tells you directly: when `n` is `0`, the result is `0`.

The base case is what stops the recursion. Without it, the function would call itself forever (until the runtime stack overflows and the program crashes).

### (b) Recursive case: when `n > 0`, return `n + sum(n - 1)`. [1 mark]

The recursive case is "everything that is not the base case." It is where the function calls itself with a smaller version of the problem.

The pattern here:
- The work for `n` is "add `n` to the sum of everything smaller."
- "Everything smaller" is `sum(n - 1)`, which the function trusts itself to compute correctly.

This is the structural pattern of every recursive function: solve a small version yourself, trust the recursive call to handle the rest.

### (c) C++ implementation [2 marks]

```cpp
int sum(int n) {
    if (n == 0) {
        return 0;
    }
    return n + sum(n - 1);
}
```

### How to write it from a piecewise definition

Every piecewise mathematical definition translates to C++ in the same shape:

1. The condition becomes an `if`.
2. The "then" branch returns the simple value (the base case).
3. Anything after the `if` (or in an `else`) handles the recursive case.

You can also write it with an explicit `else`:

```cpp
int sum(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n + sum(n - 1);
    }
}
```

Both are full marks.

### Mark allocation

- 1 mark: correct base case (`if (n == 0) return 0;`).
- 1 mark: correct recursive case (`return n + sum(n - 1);` — must include both the `n +` and the recursive call to `sum(n - 1)`).

### Common pitfalls

- **Forgetting the `return` in the base case.** Writing `if (n == 0) { 0; }` does not return anything; the function falls through to the recursive call with `n == 0`, which causes infinite recursion.
- **Using `n--` or `n - 1` inconsistently.** The recursive call should be `sum(n - 1)`. Writing `sum(n--)` modifies `n` in place, which works in C++ but is confusing and harder to reason about.
- **Calling the function with the wrong argument.** A common slip is writing `return n + sum(n)` (passing `n` again), which causes infinite recursion.
- **Adding to a wrong base case.** Writing `if (n == 1) return 1;` works for `sum(n)` where `n >= 1`, but fails for `sum(0)` (which the question's definition says should return `0`).

---

## After this test

This was the easy Unit G test. Roughly:

- **18–22 marks:** Unit G basics are solid. Move on to Unit G #2 for harder pattern composition.
- **13–17 marks:** mostly there, but specific topics (Plans, do-while behaviour, recursive base cases) need another look. Replay the Day 2 video and try Unit G #2 in a day or two.
- **8–12 marks:** real gaps. Go back to Lectures 17, 18, 19 (or the Unit G theory page) before pushing on.
- **Below 8:** retake Foundations Test #3 first; come back to Unit G when you are scoring above 18 there.

### Logo coverage

This test contained one Logo→C++ conversion (Q3) — a single `REPEAT` loop with an explicit counter variable. A COS 132 lecturer recently confirmed (via a student in the group) that Logo→C++ conversions are examinable in ST2. This question represents the easiest shape of what you might see.
