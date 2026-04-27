# Day 2 — Code with Swift — The Gym Tally

Good day, good people. This is the Day 2 reproduction drill. Below is the problem, the expected I/O, and how to use the video.

---

## The task

Caleb's been logging his weights at the gym, but he's sick of doing the maths himself. He wants a small C++ program that:

1. Asks for one weight (in kilograms) at a time.
2. Stops when he enters `-1` (the sentinel).
3. Tracks the heaviest weight he entered.
4. Counts how many of his lifts were strictly above `95 kg` (his "personal bests").
5. Prints both the heaviest lift and the count of personal bests at the end.

You'll do the work using two helper functions called from `main` — one that updates the running maximum, and one that conditionally bumps a counter. This is your first time writing your own helper functions in this programme.

## What the program should do (exact I/O)

When you compile and run your version, it should behave like this:

```
$ ./gym
Enter weights one at a time. -1 to stop.
Weight: 80
Weight: 100
Weight: 120
Weight: 90
Weight: -1
Heaviest: 120
Personal bests (>95): 2
```

The user enters weights one at a time. After they type `-1`, the program prints the heaviest and the count.

## What you'll learn

- **Architecture stage:** Stage 1 → 2 — still a single file, but for the first time you'll declare functions **above** `main` and define them **below**. The body of `main` calls the helpers instead of doing the work inline.
- **Patterns:** three of the eight from Lecture 17, composed in one loop.
  - **Plan C — Sentinel-driven loop.** You don't know how many weights Caleb will type. Loop until he enters `-1`.
  - **Plan G — Find the largest.** Track the heaviest weight seen so far. Update it whenever a bigger one comes in.
  - **Plan E — Count values matching a condition.** Count how many lifts are strictly greater than `95`.

By the end you'll have written your first multi-function program. Tomorrow we move into recursion.

---

## How to use this video (the reproduction loop)

1. **Watch the whole video once. Don't pause, don't take notes.** Just follow along.
2. **Close the video.** Open `starter/main.cpp` in your editor.
3. **Write the program from scratch.** From a blank file, looking only at the I/O specification above. If you get stuck, write what you can and mark where you got lost — don't peek at the solution.
4. **Compile and run** in Codespaces:
   ```
   g++ -std=c++98 -Wall starter/main.cpp -o gym
   ./gym
   ```
   Try it with a few different sets of inputs (including a Caleb-cheats-and-stops-after-one-rep edge case).
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
