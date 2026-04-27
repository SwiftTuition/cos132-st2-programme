# COS 132 — Foundations Test #1

**Module:** COS 132 — Imperative Programming
**Assessment:** Foundations Test #1 (ST2 Programme)
**Set by:** Swift Tuition
**Duration:** 30 minutes
**Total Marks:** 22
**Difficulty:** Easy — diagnostic baseline

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

i. The `cin` operator can read a string containing spaces directly into a `string` variable. (1)

ii. The `<iomanip>` header must be included to use the `setw` function. (1)

iii. In C++, the operator `=` is used for assignment, and `==` is used for comparison. (1)

iv. A function in C++ can have a default value for its parameters, but only for the leftmost parameters. (1)

### (b) For each of the questions below, choose the most correct option.

i. Which of the following C++ statements correctly declares a constant for the value of pi? (1)
   A. `int PI = 3.14159;`
   B. `const double PI = 3.14159;`
   C. `double const PI;`
   D. `define PI 3.14159;`

ii. Which one of the following expressions evaluates to `7`? (1)
   A. `15 / 2`
   B. `15 % 2`
   C. `15.0 / 2`
   D. `15 / 2.0`

iii. Which header file must be included to use `cout` and `cin`? (1)
   A. `<stdio.h>`
   B. `<iostream>`
   C. `<string>`
   D. `<iomanip>`

iv. Which of the following is the correct way to declare a function that takes two integers and returns their sum? (1)
   A. `int add(int, int);`
   B. `void add(int a, int b);`
   C. `add(int a, int b): int;`
   D. `function int add(int a, int b);`

---

## Question 2 [6 marks]

For each of the following programs, study the code and provide the exact output the program would produce.

### (a)
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 7;
    int b = 3;
    cout << a / b << " " << a % b;
    return 0;
}
```
(2)

### (b)
```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 5;
    int y = x++;
    int z = ++x;
    cout << x << " " << y << " " << z;
    return 0;
}
```
(2)

### (c)
```cpp
#include <iostream>
using namespace std;

int compute(int n) {
    return n * 2;
}

double compute(double n) {
    return n + 0.5;
}

int main() {
    cout << compute(4) << " " << compute(4.0);
    return 0;
}
```
(2)

---

## Question 3 [4 marks]

Consider the following Logo procedure:

```logo
TO PRINT_LINE :N
  REPEAT :N [
    PRINT "*
  ]
END
```

The procedure prints `:N` lines, each containing a single asterisk.

Convert the Logo procedure into an equivalent C++ function called `printLine` that takes one `int` parameter and produces the same output. You do **not** need to write a `main` function. Assume `iostream` and the `std` namespace are available.

---

## Question 4 [4 marks]

Write **single C++ statements** that perform each of the following tasks. You may assume any necessary headers are included and that the `std` namespace is in use.

(a) Declare an integer variable called `count` and initialise it to zero. (1)

(b) Read a full line of text (including spaces) from standard input into a `string` variable called `name`. (1)

(c) Print the value of a `double` variable called `total` with exactly **2** digits after the decimal point. (1)

(d) Calculate the average of two `int` variables `a` and `b` as a `double`, and store the result in a `double` variable called `avg`. (Use a type cast.) (1)

---

*End of paper · 22 marks · 30 minutes*
