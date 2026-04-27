---
title: Unit G Test #1
assessment: Unit G Test #1 (ST2 Programme)
totalMarks: 22
style: g1
tex: unit_g_test_1.tex
pdf: unit_g_test_1.pdf
compiler: xelatex
---

# COS 132 — Unit G Test #1

**Module:** COS 132 — Imperative Programming
**Assessment:** Unit G Test #1 (ST2 Programme)
**Set by:** Swift Tuition
**Duration:** 30 minutes
**Total Marks:** 22
**Difficulty:** Easy — pattern recognition, simple translation, one recursive case
**Scope:** Lectures 17 (Coding Patterns), 18 (Repetition Translation), 19 (Simple Recursion)

---

## Instructions

1. Read each question carefully and answer all of them.
2. Write your answers in a separate file or on paper. Do not edit this question paper.
3. The assessment comprises **4** questions over **22** marks.
4. This is a closed-book assessment. No internet, no notes, no compiler.
5. You have **30 minutes** to complete the paper.

| Question: | 1 | 2 | 3 | 4 | Total |
|---|---|---|---|---|---|
| Marks: | 8 | 6 | 4 | 4 | 22 |

---

## Question 1 [8 marks]

### (a) For each of the statements below, state whether the statement is **True** or **False**.

i. The Swap plan (Plan H) requires a temporary variable to exchange two values without losing data. (1)

ii. A `do-while` loop is guaranteed to execute its body at least once, regardless of the loop condition. (1)

iii. The Count plan (Plan E) initialises its counter variable to `1` before the loop. (1)

iv. The Search plan (Plan I) typically uses a boolean flag variable to record whether the target value has been found. (1)

### (b) For each of the questions below, choose the most correct option.

i. Which plan from Lecture 17 best describes the scenario "Read exactly 10 exam marks and accumulate their total"? (1)
   A. Plan A only (read known count)
   B. Plan F only (accumulate)
   C. Plan A combined with Plan F
   D. Plan G (find largest)

ii. Which loop form is guaranteed to execute its body at least once, regardless of the condition? (1)
   A. `for`
   B. `while`
   C. `do-while`
   D. None of the above

iii. A programmer needs to write a function that searches a list of integers for a target value and stops as soon as the target is found. Which plan from Lecture 17 is most appropriate? (1)
   A. Plan E (Count)
   B. Plan F (Accumulate)
   C. Plan G (Find largest)
   D. Plan I (Search)

iv. Which of the following code fragments correctly swaps the values of two `int` variables `a` and `b` using the temp-variable approach from Plan H in Lecture 17? (1)
   A. `a = b; b = a;`
   B. `int temp = a; a = b; b = temp;`
   C. `int temp = a; a = temp; b = a;`
   D. `a, b = b, a;`

---

## Question 2 [6 marks]

For each of the following programs, study the code and provide the exact output the program would produce.

### (a)
```cpp
#include <iostream>
using namespace std;

int main() {
    for (int i = 5; i >= 1; i--) {
        cout << i << " ";
    }
    return 0;
}
```
(2)

### (b)
Assume the program reads the input sequence `7 4 9 -1`.

```cpp
#include <iostream>
using namespace std;

int main() {
    int value;
    int count = 0;
    cin >> value;
    while (value != -1) {
        count++;
        cin >> value;
    }
    cout << count;
    return 0;
}
```
(2)

### (c)
```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 10;
    do {
        cout << x;
        x--;
    } while (x > 10);
    return 0;
}
```
(2)

---

## Question 3 [4 marks]

Consider the following Logo procedure:

```logo
TO PRINT_NUMBERS :N
  MAKE "I 1
  REPEAT :N [
    PRINT :I
    MAKE "I :I + 1
  ]
END
```

The procedure prints the numbers from `1` up to `:N`, each on its own line.

### (a) Convert the Logo procedure into an equivalent C++ function called `printNumbers` that takes one `int` parameter and produces the same output. You do **not** need to write a `main` function. Assume `iostream` and the `std` namespace are available. (3)

### (b) Which plan from Lecture 17 does this procedure implement? (1)

---

## Question 4 [4 marks]

A C++ function `sum` is defined recursively to compute the sum of integers from `1` to `n`:

$$
\text{sum}(n) = \begin{cases} 0 & \text{if } n = 0 \\ n + \text{sum}(n-1) & \text{if } n > 0 \end{cases}
$$

### (a) State the **base case** of this function. (1)

### (b) State the **recursive case** of this function. (1)

### (c) Write the complete C++ function `int sum(int n)` that implements this definition. (2)

---

*End of paper · 22 marks · 30 minutes*
