# Day 1 — Code with Swift — Total the Quiz Scores

**Scenario:** You've just marked five quiz scripts. You want a quick way to add up the total class score so you can work out the average later. We'll write a small C++ program that does that for you.

**Architecture stage:** Stage 1 — single file, everything in `main()`. No functions of your own yet, no headers beyond `<iostream>`.

**Patterns used:**
- **Read a known number of values** — we know there are five scripts, so the loop runs exactly five times.
- **Accumulate a running total** — start at zero, add each score as we read it.

**Video length:** about 12 minutes.

---

## How to use this video (the reproduction loop)

1. **Watch the whole video once. Don't pause, don't take notes.** Just follow along.
2. **Close the video.** Open `starter/main.cpp` in your editor.
3. **Write the program from scratch.** From the blank file. If you get stuck, write what you can and mark where you got lost — don't peek.
4. **Compile and run** in Codespaces:
   ```
   g++ -std=c++98 -Wall starter/main.cpp -o quiz
   ./quiz
   ```
5. **Compare to the solution.** Open `solution/main.cpp` and look at it next to your version. Note any differences.
6. **Re-watch only the section you got stuck on.** Then write it from scratch a second time.

The second pass is where the pattern locks in. Don't skip it.

---

## What you'll have at the end

A program that runs like this:

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

That's the whole brief.

---

## Files in this folder

| File | What it is |
|---|---|
| `starter/main.cpp` | Empty file. This is where you write your version. |
| `solution/main.cpp` | The completed code from the video. Open it **after** you've attempted the program yourself. |
| `video-script.md` | The script for the video, beat by beat. Useful if you want to read the explanation instead of re-watching. |
| `README.md` | This file. |
