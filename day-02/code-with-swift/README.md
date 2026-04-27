# Day 2 — Code with Swift — The Gym Tally

**Scenario:** Caleb's been logging his weights at the gym, but he is sick of doing the maths himself. He wants a small C++ program that asks for one weight at a time, stops when he enters `-1`, and tells him two things: what the heaviest lift was, and how many of his lifts were over 95 kilograms (his "personal bests").

**Architecture stage:** Stage 1 → 2 — single file, but for the first time in the programme we declare functions **above** `main` and define them **below**. The body of `main` calls the helper functions instead of doing the work inline.

**Patterns used (three of L17's plans, composed):**
- **Plan C — Sentinel-driven loop.** We do not know how many weights Caleb will type. We loop until he enters `-1`.
- **Plan G — Find the largest.** Track the heaviest weight seen so far. Update it whenever a bigger one comes in.
- **Plan E — Count values matching a condition.** Count how many lifts are strictly greater than `95`.

**Video length:** about 14 minutes.

---

## How to use this video (the reproduction loop)

1. **Watch the whole video once. Don't pause, don't take notes.** Just follow along.
2. **Close the video.** Open `starter/main.cpp` in your editor.
3. **Write the program from scratch.** From the blank file. If you get stuck, write what you can and mark where you got lost — don't peek.
4. **Compile and run** in Codespaces:
   ```
   g++ -std=c++98 -Wall starter/main.cpp -o gym
   ./gym
   ```
5. **Compare to the solution.** Open `solution/main.cpp` and look at it next to your version. Note any differences.
6. **Re-watch only the section you got stuck on.** Then write it from scratch a second time.

The second pass is where the pattern locks in. Don't skip it.

---

## What you'll have at the end

A program that runs like this:

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

Two helper functions called from `main` (one for the max, one for the conditional count). That's the whole brief.

---

## Files in this folder

| File | What it is |
|---|---|
| `starter/main.cpp` | Empty file. This is where you write your version. |
| `solution/main.cpp` | The completed code from the video. Open it **after** you've attempted the program yourself. |
| `video-script.md` | The script for the video, beat by beat. Useful if you want to read the explanation instead of re-watching. |
| `README.md` | This file. |
