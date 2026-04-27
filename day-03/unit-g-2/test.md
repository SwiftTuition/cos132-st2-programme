---
title: Unit G Test #2
assessment: Unit G Test #2 (ST2 Programme)
totalMarks: 24
style: g2
tex: unit_g_test_2.tex
pdf: unit_g_test_2.pdf
compiler: xelatex
---

# COS 132 — Unit G Test #2

**Module:** COS 132 — Imperative Programming
**Assessment:** Unit G Test #2 (ST2 Programme)
**Set by:** Swift Tuition
**Duration:** 30 minutes
**Total Marks:** 24
**Difficulty:** Medium — combining concepts, translation rules, recursive analysis
**Scope:** Lectures 17 (Coding Patterns), 18 (Repetition Translation), 19 (Simple Recursion)

---

## Instructions

1. Read each question carefully and answer all of them.
2. Write your answers in a separate file or on paper. Do not edit this question paper.
3. The assessment comprises **4** questions over **24** marks.
4. This is a closed-book assessment. No internet, no notes, no compiler.
5. You have **30 minutes** to complete the paper.

| Question: | 1 | 2 | 3 | 4 | Total |
|---|---|---|---|---|---|
| Marks: | 8 | 6 | 5 | 5 | 24 |

---

## Question 1 [8 marks]

### (a) For each of the statements below, state whether the statement is **True** or **False**.

i. Every `while` loop can be rewritten as an equivalent `for` loop without modifying the structure of the `for` loop. (1)

ii. When converting a `for` loop to a `do-while` loop, the loop variable's initialisation goes **before** the `do` keyword. (1)

iii. Indirect (mutual) recursion is when a function calls itself directly within its own body. (1)

iv. A `for` loop with an empty update clause, written as `for (init; condition; )`, is usually a sign that a `while` loop would be more idiomatic. (1)

### (b) For each of the questions below, choose the most correct option.

i. A `for` loop and its converted `do-while` version will **NOT** be equivalent in which of the following cases? (1)
   A. The loop body has a side effect on a global variable.
   B. The loop's initial condition is `false` (so the `for` loop would never enter its body).
   C. The loop variable is declared inside the `for` header.
   D. The loop contains a `break` statement.

ii. What is the output of the following code? (1)
   ```cpp
   int x = 0;
   do {
       cout << x;
       x = x + 1;
   } while (x > 5);
   ```
   A. (no output, the condition is false at the start)
   B. `0`
   C. `0123456`
   D. The loop runs forever.

iii. Which two plans from Lecture 17 would you compose to solve "read 5 numbers and find the largest"? (1)
   A. Plan A (read known count) and Plan F (accumulate)
   B. Plan A (read known count) and Plan G (find largest)
   C. Plan C (sentinel) and Plan G (find largest)
   D. Plan B (read count first) and Plan E (count)

iv. Which one of the following `while` loops can be **safely** converted to a `for` loop? (1)
   A. `cin >> x; while (x != -1) { sum += x; cin >> x; }`
   B. `bool found = false; while (!found && i < n) { if (arr[i] == target) found = true; i++; }`
   C. `int i = 0; while (i < 10) { cout << i; i++; }`
   D. `while (true) { cin >> x; if (x == 0) break; }`

---

## Question 2 [6 marks]

### (a) Sentinel-driven sum [3 marks]

Assume the program reads the input sequence `5 12 8 -1`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int value;
    int sum = 0;
    int count = 0;
    cin >> value;
    while (value != -1) {
        sum = sum + value;
        count++;
        cin >> value;
    }
    cout << sum << " " << count;
    return 0;
}
```

Provide the exact output the program would produce.

### (b) Translation divergence [3 marks]

Consider the following two pieces of code, which both attempt to print all integers from `start` down to `1`. Assume the user enters `0` for `start` in both versions.

**Version A (`for` loop):**
```cpp
int start;
cin >> start;
for (int i = start; i >= 1; i--) {
    cout << i << " ";
}
```

**Version B (`do-while` translation):**
```cpp
int start;
cin >> start;
int i = start;
do {
    cout << i << " ";
    i--;
} while (i >= 1);
```

(i) What does Version A output? (1)
(ii) What does Version B output? (1)
(iii) Briefly explain why the two outputs are different. (1)

---

## Question 3 [5 marks]

Consider the following Logo procedure:

```logo
TO PRINT_PATTERN :N
  MAKE "I 1
  REPEAT :N [
    IF (:I MOD 2) = 1 [PRINT1 "*]
    IF (:I MOD 2) = 0 [PRINT1 "-]
    MAKE "I :I + 1
  ]
  PRINT ""
END
```

The procedure prints a single line of `:N` characters, alternating `*` (for odd positions) and `-` (for even positions). For example, `PRINT_PATTERN 6` produces:

```
*-*-*-
```

`PRINT1` prints without a newline; `PRINT ""` prints an empty line (a newline).

### (a) Convert the Logo procedure into an equivalent C++ function called `printPattern` that takes one `int` parameter and produces the same output. You do **not** need to write a `main` function. Assume `iostream` and the `std` namespace are available. (4)

### (b) Now rewrite the body of your C++ function using a `while` loop instead of a `for` loop. Provide only the function body. (1)

---

## Question 4 [5 marks]

Study the following recursive C++ function carefully.

```cpp
int f(const int a, const int b) {
    if (b == 0) {
        return 1;
    }
    return a * f(a, b - 1);
}
```

### (a) Output prediction [1 mark]

What is the value of `f(2, 4)`?

### (b) Identification [3 marks]

(i) In one short sentence, what does this function compute? (1)

(ii) State the **base case** of the function. (1)

(iii) State the **recursive case** of the function. (1)

### (c) Mathematical notation [1 mark]

Write this function as a piecewise mathematical definition. Use the function name `f(a, b)`.

---

*End of paper · 24 marks · 30 minutes*
