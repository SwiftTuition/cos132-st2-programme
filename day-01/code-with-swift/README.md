# Day 1 — Code with Swift — Total the Quiz Scores

Good day, good people. This is the Day 1 reproduction drill. Below is the problem, the expected I/O, and how to use the video.

---

## The task

You're going to write a small C++ program that does the following:

1. Stores the constant `5` as the number of quiz scripts to mark.
2. Asks the user to enter that many quiz scores, one at a time.
3. Adds each score into a running total as it comes in.
4. Prints the total at the end.

No menus, no fancy formatting, no input validation. Five reads, one running total, one print.

## What the program should do (exact I/O)

When you compile and run your version, it should behave exactly like this:

```
$ ./quiz
Enter 5 quiz scores:
Score 1: 85
Score 2: 72
Score 3: 91
Score 4: 68
Score 5: 79
Total: 395
```

The user types each score after the prompt. Your program prints the prompts, reads the values, and prints `Total: <sum>` on the last line.

## What you'll learn

- **Architecture stage:** Stage 1 — single file, everything inside `main()`. No functions of your own yet.
- **Patterns:** the first two of the eight from Lecture 17.
  - **Plan A — Read a known number of values.** We know we're reading five, so the loop runs exactly five times.
  - **Plan F — Accumulate a running total.** Start at zero, add each score as it comes in.

By the end you'll have written your first program that composes two L17 plans together. Tomorrow we add a third plan and start writing helper functions.

---

## How to use this video (the reproduction loop)

1. **Watch the whole video once. Don't pause, don't take notes.** Just follow along.
2. **Close the video.** Open `starter/main.cpp` in your editor.
3. **Write the program from scratch.** From a blank file, looking only at the I/O specification above. If you get stuck, write what you can and mark where you got lost — don't peek at the solution.
4. **Compile and run** in Codespaces:
   ```
   g++ -std=c++98 -Wall starter/main.cpp -o quiz
   ./quiz
   ```
   Try it with a few different sets of inputs to convince yourself it works.
5. **Compare to the solution.** Open `solution/main.cpp` and look at it next to your version. Note any differences.
6. **Re-watch only the section you got stuck on.** Then write the program from scratch a second time.

The second pass is where the pattern locks in. Don't skip it.

---

## Files in this folder

| File | What it is |
|---|---|
| `README.md` | This file. The brief, the I/O contract, and how to use the video. |
| `starter/main.cpp` | Empty file. This is where you write your version. |
| `solution/main.cpp` | The completed code from the video. Open it **after** you've attempted the program yourself. |

---

## Video link

(coming — will be linked here once recorded)
