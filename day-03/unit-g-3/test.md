---
title: Unit G Test #3
assessment: Unit G Test #3 (ST2 Programme)
totalMarks: 25
style: g3
tex: unit_g_test_3.tex
pdf: unit_g_test_3.pdf
compiler: xelatex
---

# COS 132 — Unit G Test #3

**Module:** COS 132 — Imperative Programming
**Assessment:** Unit G Test #3 (ST2 Programme)
**Set by:** Swift Tuition
**Duration:** 30 minutes
**Total Marks:** 25
**Difficulty:** Hard — exam-realistic ST2 simulation
**Scope:** Lectures 17 (Coding Patterns), 18 (Repetition Translation), 19 (Simple Recursion)

---

## Instructions

1. Read each question carefully and answer all of them.
2. Write your answers in a separate file or on paper. Do not edit this question paper.
3. The assessment comprises **4** questions over **25** marks.
4. This is a closed-book assessment. No internet, no notes, no compiler.
5. You have **30 minutes** to complete the paper.

| Question: | 1 | 2 | 3 | 4 | Total |
|---|---|---|---|---|---|
| Marks: | 8 | 7 | 5 | 5 | 25 |

---

## Question 1 [8 marks]

### (a) For each of the statements below, state whether the statement is **True** or **False**.

i. In mutual (indirect) recursion, all functions involved must be declared (prototyped) before any of their definitions, otherwise the compiler will not know about the function being called from the other. (1)

ii. A recursive function without a base case will always produce a **compile-time** error in C++. (1)

iii. The Search plan (Plan I) uses a boolean flag, initialised to `false`, and continues looping while the flag is `false` and there are still values to check. (1)

iv. `for (;;)` and `while (true)` produce identical machine behaviour, but `while (true)` is the more idiomatic choice for an intentional infinite loop. (1)

### (b) For each of the questions below, choose the most correct option.

i. Consider the following recursive function: (1)
   ```cpp
   void f(int n) {
       if (n <= 0) return;
       cout << n << " ";
       f(n - 1);
   }
   ```
   What is the output of `f(3)`?
   A. `1 2 3 `
   B. `3 2 1 `
   C. `1 2 3 4 `
   D. The function recurses forever.

ii. A programmer needs to search a list of integers for a target value and stop as soon as the target is found. Which plan from Lecture 17 is most appropriate? (1)
   A. Plan A (Read known count)
   B. Plan E (Count values)
   C. Plan G (Find largest)
   D. Plan I (Search)

iii. A recursive function calls itself with arguments that never get smaller (or otherwise never reach the base case). What happens at runtime? (1)
   A. The compiler refuses to compile the program.
   B. The function returns `0` by default.
   C. The runtime stack fills up and the operating system terminates the program (a "stack overflow").
   D. The function returns once and produces a single output line.

iv. Which one of the following code fragments correctly implements mutual recursion for `isEven` and `isOdd` (where each function decides if its `int` argument is even or odd by delegating to the other)? (1)

   A.
   ```cpp
   bool isEven(int n) { return n == 0 ? true : isEven(n - 1); }
   bool isOdd(int n)  { return n == 0 ? false : isOdd(n - 1); }
   ```
   B.
   ```cpp
   bool isEven(int n);
   bool isOdd(int n);
   bool isEven(int n) { return n == 0 ? true : isOdd(n - 1); }
   bool isOdd(int n)  { return n == 0 ? false : isEven(n - 1); }
   ```
   C.
   ```cpp
   bool isEven(int n) { return isOdd(n - 1); }
   bool isOdd(int n)  { return isEven(n - 1); }
   ```
   D.
   ```cpp
   bool isEven(int n) { if (n == 0) return true; isOdd(n - 1); }
   bool isOdd(int n)  { if (n == 0) return false; isEven(n - 1); }
   ```

---

## Question 2 [7 marks]

### (a) Bidirectional recursion trace [4 marks]

Study the following recursive function:

```cpp
void mystery(int n) {
    if (n == 0) return;
    cout << n << " ";
    mystery(n - 1);
    cout << n << " ";
}
```

What is the exact output of `mystery(3)`?

> Hint: this function prints `n` **before** the recursive call **and** after it.

### (b) Find the bug [3 marks]

The function below is intended to compute the sum of the digits of a non-negative integer. For example, the digit sum of `123` should be `6` (because `1 + 2 + 3 = 6`).

```cpp
int sumDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return (n / 10) + sumDigits(n / 10);
}
```

(i) State, in one short sentence, what the function actually does (note: this is a buggy version, so describe the buggy behaviour). (1)

(ii) Identify the line containing the bug, and write the corrected version of that single line. (2)

---

## Question 3 [5 marks]

Consider the following recursive Logo procedure:

```logo
TO COUNTDOWN :N
  IF :N = 0 [STOP]
  PRINT :N
  COUNTDOWN :N - 1
END
```

The procedure prints the integers from `:N` down to `1`, each on its own line, using direct recursion (not a `REPEAT` loop). The Logo command `STOP` ends the current procedure call (it is the equivalent of `return;` in C++).

### (a) State the **base case** of the Logo procedure. (1)

### (b) Convert the Logo procedure into an equivalent C++ recursive function called `countdown` that takes one `int` parameter and produces the same output. You do **not** need to write a `main` function. Assume `iostream` and the `std` namespace are available. Your C++ function must use direct recursion, not a loop. (3)

### (c) What is the exact output of `COUNTDOWN 3`? (1)

---

## Question 4 [5 marks]

Write a complete C++ function with the following specification:

```cpp
void analyseMarks(int n);
```

The function must do the following:

1. Read exactly `n` integer marks from `cin`. Each mark is between `0` and `100`.
2. Count how many of the marks are **strictly greater than 50** (i.e. the count of "passing" marks).
3. Accumulate the total of all marks.
4. After the loop, print the count of passing marks and the average of all the marks (the average must be a `double`, calculated correctly), in this exact format:

```
Passing:_{count}$
Average:_{average}$
```

Where `_` is a single space and `$` is a newline. Use default `cout` formatting for the average value (do not call `setprecision` or `fixed`).

Assume `iostream` and the `std` namespace are available. You may also assume `n > 0` (no need to guard against an empty case).

---

*End of paper · 25 marks · 30 minutes*
