---
title: Unit G Test #2 Memo
assessment: Unit G Test #2 (ST2 Programme)
totalMarks: 24
style: g2
tex: unit_g_test_2_memo.tex
pdf: unit_g_test_2_memo.pdf
compiler: xelatex
---

# COS 132 — Unit G Test #2 — Memo

Good day, good people. Below is the worked solution for Unit G Test #2. Read the reasoning, not just the answers.

**Total marks:** 24

---

## Question 1 [8 marks]

### (a) True or False

**i. False.** [1 mark]

Not every `while` loop translates cleanly to a `for` loop. The lecture is explicit about this. A `for` loop expects three things: an initialisation, a condition that depends on a loop variable, and an update step at the end of each iteration. If the `while` loop does not fit that shape, you cannot translate it without "abusing" the `for` syntax (for example, leaving the update field empty).

The classic example is a sentinel-driven loop:

```cpp
cin >> value;
while (value != -1) {
    sum += value;
    cin >> value;
}
```

There is no single loop variable being updated cleanly at the end. The "update" is reading new input. Forcing this into a `for` loop would look like `for (cin >> value; value != -1; cin >> value)`, which is technically legal but considered an abuse of `for`.

`for` works cleanly when the loop has a known shape — a counter variable, a condition that depends on it, and a predictable update at the end of each iteration. For everything else (sentinels, search-with-flag, irregular updates), a `while` loop is the more honest choice.

---

**ii. True.** [1 mark]

When you translate a `for` loop to a `do-while`, the structure becomes:

```cpp
// for (init; cond; update) { body; }
//   becomes
init;
do {
    body;
    update;
} while (cond);
```

The initialisation has to happen **before** the `do` block so the loop variable exists by the time the body runs. Otherwise the body has no idea what the loop variable is.

```cpp
int i = 0;        // initialisation, OUTSIDE and BEFORE
do {
    cout << i;    // body
    i++;          // update
} while (i < 5);  // condition
```

If you put `int i = 0;` inside the `do` block, it would re-initialise on every iteration and the loop would never terminate.

---

**iii. False.** [1 mark]

That's the definition of **direct** recursion, not indirect (mutual) recursion. The two are different:

- **Direct recursion**: function `A` calls function `A`. Most recursive functions you write are direct.
- **Indirect (mutual) recursion**: function `A` calls function `B`, which calls function `A` (possibly through more functions in between). The classic textbook example is `is_even(n)` calling `is_odd(n-1)`, and `is_odd(n)` calling `is_even(n-1)`. Each function delegates to the other, and they only stop when the base cases (at `n = 0`) are reached.

Mutual recursion needs both function prototypes declared before either body, otherwise the compiler will not know about the function being called.

---

**iv. True.** [1 mark]

When you write `for (init; condition; )` with an empty update clause, the `for` loop is doing the work of a `while` loop. The third slot was designed to hold the loop variable's update step. If there is no clean update to put there, the `for` is fighting the language's intent.

Compare:

```cpp
// for with empty update — looks awkward
for (cin >> value; value != -1; ) {
    sum += value;
    cin >> value;
}

// the same logic as a while — looks natural
cin >> value;
while (value != -1) {
    sum += value;
    cin >> value;
}
```

The `while` version is shorter and the structure tells you exactly what is going on: keep going until the sentinel arrives. The `for` version forces you to read the empty third slot and wonder where the update is.

---

### (b) Multiple choice

**i. B.** Initial condition is `false`. [1 mark]

This is the case where `for` and `do-while` truly diverge. A `for` loop checks its condition **before** running the body for the first time. If the condition is false from the start, the body never runs. A `do-while` always runs the body once before its first check, so it cannot match a `for` whose body is supposed to skip entirely.

The other options:
- **A** Side effects are independent of which loop form you use; they happen whenever the body runs.
- **C** Where the loop variable is declared does not change the equivalence of the two forms.
- **D** A `break` works the same way in both `for` and `do-while`.

This question maps directly to ST2 2024 Q6, where the divergence is the key learning.

---

**ii. B.** `0`. [1 mark]

Trace the `do-while` with `x = 0`:

- Enter the `do` block. Print `x`, which is `0`. Then `x = x + 1` makes `x = 1`.
- Check condition: `1 > 5` is `false`. Exit.

Output: `0`. Just one character, because the body ran once before the condition check failed.

> The trap is option A. A student who misreads `do-while` as `while` (condition checked first) might think the loop never enters and outputs nothing. But `do-while` always runs the body once first.

---

**iii. B.** Plan A (read known count) and Plan G (find largest). [1 mark]

Two plans, two jobs:

- "Read 5 numbers" is a known count, so Plan A drives the loop.
- "Find the largest" is Plan G, which initialises a `largest` variable before the loop and updates it inside whenever a bigger value comes in.

Why not the others:
- **A** uses Plan F (Accumulate), which is for sums and totals. We are not summing here.
- **C** uses Plan C (Sentinel), but the question says exactly 5 numbers. There is no sentinel.
- **D** uses Plan E (Count), which counts how many values match a condition. We are not counting; we are tracking a maximum.

---

**iv. C.** `int i = 0; while (i < 10) { cout << i; i++; }`. [1 mark]

This is the textbook shape of a `while` that translates cleanly to `for`:

```cpp
// while form
int i = 0;
while (i < 10) {
    cout << i;
    i++;
}

// for form (clean)
for (int i = 0; i < 10; i++) {
    cout << i;
}
```

There is one loop variable (`i`), the condition only depends on it, and the update happens at the end of the body. All the requirements for a `for` are met.

The other options have problems:
- **A** sentinel loop (no clean loop variable; the "update" is an input read).
- **B** Search loop (two condition variables, plus an update inside an `if` — not a single, predictable end-of-body update).
- **D** intentional infinite loop with `break` — `for (;;)` exists but `while (true)` is more idiomatic for this case.

---

## Question 2 [6 marks]

### (a) Output: `25 3` [3 marks]

This is Plan C (Sentinel) plus Plan F (Accumulate) plus Plan E (Count) all composed in one loop. Trace with input `5 12 8 -1`:

| read | check `value != -1` | sum | count |
|---|---|---|---|
| `5` | true | `0 + 5 = 5` | `1` |
| `12` | true | `5 + 12 = 17` | `2` |
| `8` | true | `17 + 8 = 25` | `3` |
| `-1` | false → exit | (unchanged) | (unchanged) |

Output: `25 3` (sum, then space, then count).

> If you got `24 4`, you counted the sentinel and added it to the sum. Plan C reads the next value at the **end** of the loop body, then re-checks. The sentinel itself is never processed.

---

### (b) Translation divergence [3 marks]

**(i) Version A output: (no output)** [1 mark]

The `for` loop checks its condition before the first iteration. With `start = 0`, the condition `i >= 1` (where `i = 0`) is `false` immediately. The loop body never runs. Nothing is printed.

**(ii) Version B output: `0 `** [1 mark]

The `do-while` runs its body **before** the first condition check. So even with `i = 0`, the body executes once: it prints `0 ` and then decrements `i` to `-1`. Then the condition `i >= 1` is `false` (`-1 >= 1` is false), and the loop exits.

Output: `0 ` (a `0` followed by a space). One iteration ran.

**(iii) Why the outputs differ** [1 mark]

This is the same issue covered in Q1(a)(ii) and Q1(b)(i). `for` and `while` check the condition before the body runs. `do-while` runs the body once before checking. When the condition is `false` on entry, `for` skips entirely and `do-while` runs once. With `start = 0`, that is exactly what happened: `for` produced no output, `do-while` produced `0 `.

---

## Question 3 [5 marks]

### (a) Expected answer [4 marks]

```cpp
void printPattern(int n) {
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 1) {
            cout << "*";
        }
        if (i % 2 == 0) {
            cout << "-";
        }
    }
    cout << endl;
}
```

### How to think about it

The Logo procedure does these things:

1. Starts a counter `:I` at `1`.
2. Loops `:N` times.
3. Inside the loop, checks whether `:I` is odd or even, prints `*` or `-` accordingly.
4. After the loop, prints a newline.

Direct C++ translation:

- The `MAKE "I 1` plus `MAKE "I :I + 1` becomes a `for`-loop counter.
- `IF (:I MOD 2) = 1` becomes `if (i % 2 == 1)`. (Modulo is `%` in C++; it returns the remainder after division, so `5 % 2` gives `1` and `6 % 2` gives `0`.)
- `PRINT1 "*` (no newline) becomes `cout << "*";` (no `endl`).
- `PRINT ""` (just a newline) becomes `cout << endl;`. Notice this comes **after** the loop, not inside it.

### Marks breakdown

- 1 mark: function signature `void printPattern(int n)`.
- 1 mark: the loop runs `n` times, with a counter that varies as needed.
- 1 mark: the `if`s correctly distinguish odd from even and print the right character.
- 1 mark: the trailing newline appears after the loop, not inside it.

### Other valid answers

Using `else` instead of two separate `if`s is cleaner and equally valid:

```cpp
for (int i = 1; i <= n; i++) {
    if (i % 2 == 1) {
        cout << "*";
    } else {
        cout << "-";
    }
}
cout << endl;
```

A 0-indexed counter (`for (int i = 0; i < n; i++)`) works too, but flips the parity, so the conditions become `i % 2 == 0` for `*` and `i % 2 == 1` for `-`. Same output.

### Common pitfalls

- **Newline inside the loop.** `cout << endl;` after each character would print one character per line, not all on one line. The newline goes after the loop ends.
- **Off-by-one.** `i <= n` with `i` starting at `0` runs the loop `n + 1` times. Pick a consistent convention.
- **`%` confusion.** Some students think `i % 2` returns `1` when `i` is even. It returns the remainder, so `i % 2` is `0` for even and `1` for odd.

---

### (b) `while` loop version [1 mark]

```cpp
int i = 1;
while (i <= n) {
    if (i % 2 == 1) {
        cout << "*";
    }
    if (i % 2 == 0) {
        cout << "-";
    }
    i++;
}
cout << endl;
```

The translation rule: take the `for` loop's three parts and split them.

- The initialisation (`int i = 1;`) goes before the `while`.
- The condition (`i <= n`) becomes the `while` condition.
- The update (`i++`) goes at the **end** of the `while` body.

The body itself stays the same.

---

## Question 4 [5 marks]

### (a) `f(2, 4) = 16` [1 mark]

Trace the recursion:

- `f(2, 4)` returns `2 * f(2, 3)`
- `f(2, 3)` returns `2 * f(2, 2)`
- `f(2, 2)` returns `2 * f(2, 1)`
- `f(2, 1)` returns `2 * f(2, 0)`
- `f(2, 0)` returns `1` (base case)

Unwind: `f(2, 1) = 2 * 1 = 2`, `f(2, 2) = 2 * 2 = 4`, `f(2, 3) = 2 * 4 = 8`, `f(2, 4) = 2 * 8 = 16`.

So `f(2, 4) = 16`. That happens to be `2^4`, which is not a coincidence — see (b).

---

### (b) Identification [3 marks]

**(i) The function computes `a` to the power of `b`.** [1 mark]

That is, `f(a, b) = a^b` (or in C++ terms, `pow(a, b)` for integer `b >= 0`). The recursion multiplies `a` by itself `b` times.

**(ii) Base case: when `b == 0`, the function returns `1`.** [1 mark]

The function knows directly what `a^0` is (it is `1` for any non-zero `a`, and the function returns `1` regardless). No recursion needed.

**(iii) Recursive case: when `b > 0`, the function returns `a * f(a, b - 1)`.** [1 mark]

The function reduces the problem by one: instead of computing `a^b` directly, it asks "what is `a^(b-1)`?" and multiplies the answer by `a`.

This is a structural reduction — each call shrinks `b` by one, marching toward the base case.

---

### (c) Mathematical notation [1 mark]

$$
f(a, b) = \begin{cases} 1 & \text{if } b = 0 \\ a \cdot f(a, b - 1) & \text{if } b > 0 \end{cases}
$$

Or written in plain text format:

```
         { 1                  if b = 0
f(a, b) ={
         { a * f(a, b - 1)    if b > 0
```

The piecewise definition mirrors the C++ structure exactly. The `if` statement in the code corresponds to the case split in the math. The `return` value in each branch corresponds to the expression in each case.

---

## After this test

This was the medium-difficulty Unit G test. Roughly:

- **20–24 marks:** comfortable across all of Unit G. Ready for Unit G #3 and the start of Unit H next week.
- **15–19 marks:** mostly solid, but specific concepts (loop translation rules, do-while divergence, recursive case identification) need another look. Replay the relevant parts of Lectures 17, 18, 19.
- **10–14 marks:** real gaps. Retry Unit G #1 first, then come back here.
- **Below 10:** retake Foundations Test #3, then Unit G #1.

### Logo coverage

This test contained one Logo→C++ conversion (Q3) — a `REPEAT` loop combined with two `IF` statements, requiring a `for`/`if` C++ translation plus a follow-up `while`-loop variant. A COS 132 lecturer recently confirmed (via a student in the group) that Logo→C++ conversions are examinable in ST2. This question sits in the middle of what the past papers and that confirmation suggest you might see.
