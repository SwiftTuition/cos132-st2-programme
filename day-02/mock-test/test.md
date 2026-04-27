# COS 132 — Foundations Test #2

**Module:** COS 132 — Imperative Programming
**Assessment:** Foundations Test #2 (ST2 Programme)
**Set by:** Swift Tuition
**Duration:** 30 minutes
**Total Marks:** 24
**Difficulty:** Medium — combining concepts

---

## Instructions

1. Read each question carefully and answer all of them.
2. Write your answers in a separate file or on paper. Do not edit this question paper.
3. The assessment comprises **4** questions over **24** marks.
4. This is a closed-book assessment. No internet, no notes, no compiler.
5. You have **30 minutes** to complete the paper.

| Question: | 1 | 2 | 3 | 4 | Total |
|---|---|---|---|---|---|
| Marks: | 8 | 8 | 4 | 4 | 24 |

---

## Question 1 [8 marks]

### (a) For each of the statements below, state whether the statement is **True** or **False**.

i. Two functions in C++ can be overloaded if they differ **only** in their return type. (1)

ii. The expression `5 / 2 + 3.0` evaluates to `5.5` in C++. (1)

iii. A `switch` statement without `break` after a matching `case` will continue executing the statements in the next `case`. (1)

iv. The `&&` operator in C++ uses short-circuit evaluation: if the left operand is `false`, the right operand is not evaluated. (1)

### (b) For each of the questions below, choose the most correct option.

i. Given the function declaration `int compute(int a, int b = 5, int c = 10);`, which of the following calls is **invalid**? (1)
   A. `compute(1);`
   B. `compute(1, 2);`
   C. `compute(1, , 3);`
   D. `compute(1, 2, 3);`

ii. What is the value of `result` after the following code runs? (1)
   ```cpp
   int x = 10;
   int result = (x > 5) ? (x < 15 ? x * 2 : x / 2) : x;
   ```
   A. `5`
   B. `10`
   C. `20`
   D. `15`

iii. Inside a `for` loop, the keyword `continue` does which of the following? (1)
   A. Exits the loop entirely
   B. Skips the rest of the current iteration and proceeds to the next iteration
   C. Restarts the loop from the beginning
   D. Causes a compile error inside a `for` loop

iv. Which one of the following loop forms is guaranteed to execute its body **at least once**, regardless of the loop condition? (1)
   A. `for`
   B. `while`
   C. `do-while`
   D. None of the above

---

## Question 2 [8 marks]

For each of the following programs, study the code and provide the exact output the program would produce.

### (a)
```cpp
#include <iostream>
using namespace std;

int x = 10;

void f(int x) {
    x = x + 5;
    cout << x << " ";
}

int main() {
    int x = 20;
    f(x);
    cout << x;
    return 0;
}
```
(2)

### (b)
```cpp
#include <iostream>
using namespace std;

int main() {
    int n = 5;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) continue;
        sum = sum + i;
    }
    cout << sum;
    return 0;
}
```
(2)

### (c)
```cpp
#include <iostream>
using namespace std;

int main() {
    int day = 3;
    switch (day) {
        case 1: cout << "Mon ";
        case 2: cout << "Tue ";
        case 3: cout << "Wed ";
        case 4: cout << "Thu "; break;
        case 5: cout << "Fri ";
    }
    return 0;
}
```
(2)

### (d)
```cpp
#include <iostream>
using namespace std;

int main() {
    int a = 3;
    bool result = (a > 0) && (a++ < 5) && (a > 4);
    cout << result << " " << a;
    return 0;
}
```
(2)

---

## Question 3 [4 marks]

The following C++ program contains **three errors** (a mix of syntax and semantic errors). Identify each error: state whether it is a **syntax** or **semantic** error, give the **line number**, and provide a short explanation.

```cpp
1   #include <iostream>
2   using namespace std;
3
4   int main() {
5       int total = 0
6       int count = 5;
7       for (int i = 1, i <= count; i++) {
8           total += i;
9       }
10      cout << "Sum: " total << endl;
11      return 0;
12  }
```

---

## Question 4 [4 marks]

Consider the following Logo procedure:

```logo
TO COUNTDOWN :START
  MAKE "N :START
  REPEAT :START [
    PRINT :N
    MAKE "N :N - 1
  ]
END
```

The procedure prints the numbers from `:START` down to `1`, each on its own line.

Convert the Logo procedure into an equivalent C++ function called `countdown` that takes one `int` parameter and produces the same output. You do **not** need to write a `main` function. Assume `iostream` and the `std` namespace are available.

---

*End of paper · 24 marks · 30 minutes*
