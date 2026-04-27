# Day 1 — Code with Swift — Video Script

**Scenario:** Total the quiz scores
**Architecture:** Stage 1 — single file, everything in `main()`
**Length:** ~12 minutes
**Audience:** COS 132 students at the start of the ST2 programme

This is the speaking script for the video, beat by beat. Read it as a guide — feel free to deviate. Bracketed text is stage direction; un-bracketed text is what Swift says on camera.

---

## Beat 1 — Hook [0:00 – 1:00]

[ON SCREEN: a blank VS Code window with `main.cpp` empty in the editor.]

> Good day, good people. Today we're starting something new — a series called Code with Swift. Each video, I'm going to take a small everyday problem, write a C++ program from scratch to solve it, and explain every line as I go. Your job is to watch, close the video, and write the same program yourself from a blank file. That's it. That's the whole loop.

> So here's today's problem. Imagine you've just marked five quiz scripts. You want to know the total class score, so you can work out the average later. How would we get the computer to do that for us?

[Pause briefly — let students think.]

> Right. We need to read five numbers, one at a time, and add them all up. That's two things we already know how to do, just put together. Let's build it.

---

## Beat 2 — Set up the file [1:00 – 2:30]

[ON SCREEN: typing into `main.cpp`.]

> First, we need the iostream header — that's what gives us `cin` and `cout`. So:

```cpp
#include <iostream>
```

> And we'll add `using namespace std;` so I don't have to type `std::cout` everywhere. In real production code you'd usually avoid this, but for a small teaching example like this, it keeps things readable.

```cpp
using namespace std;
```

> Now the function every C++ program needs — `int main`. Returns `int`, takes no arguments, finishes with `return 0`.

```cpp
int main() {

    return 0;
}
```

> Cool. We've got a skeleton. The actual work goes between the opening brace of `main` and the `return 0`.

---

## Beat 3 — Plan it out [2:30 – 3:30]

[ON SCREEN: cursor inside main.]

> Before I write anything, let me say what I need.

> One — I need to know how many scores I'm reading. The problem says five, so let me put that in a constant. I'll call it `N`.

> Two — I need a place to keep the running total. So I need a variable for that. I'll call it `total`, and start it at zero. That's important — if I don't initialise it, I get whatever garbage was in memory before, and my answer will be wrong.

> Three — I need somewhere to put each score as I read it in. One variable, `score`, that I'll reuse for each one. I don't need five separate variables — I add each score to the total as soon as I read it, then forget about it.

> Let me write that out.

```cpp
const int N = 5;
int total = 0;
int score;
```

> Notice — `total` is initialised to `0`, but `score` doesn't need a starting value because the very first thing I'm going to do with it is read into it.

---

## Beat 4 — The loop [3:30 – 6:00]

[ON SCREEN: continuing to type.]

> Now the loop. I know I'm reading exactly five values. So a `for` loop is the natural choice.

> Let me prompt the user first so they know what's expected.

```cpp
cout << "Enter " << N << " quiz scores:" << endl;
```

> And now the loop:

```cpp
for (int i = 1; i <= N; i++) {

}
```

> Let me say what I want to happen each time through the loop.

> One — print which score we're on. So `Score 1:`, `Score 2:`, and so on.

> Two — read the score from the user.

> Three — add it to the running total.

> Three lines:

```cpp
for (int i = 1; i <= N; i++) {
    cout << "Score " << i << ": ";
    cin >> score;
    total = total + score;
}
```

> Notice I went `i = 1` to `i <= N` — so it counts 1, 2, 3, 4, 5. I could have done `i = 0; i < N` and that would also run five times, but the prompts would say "Score 0:", "Score 1:", which is strange for a human. So I picked the version that makes the output more natural. Both are correct C++; I just chose the one that reads better.

> Also — `total = total + score` — I could write that as `total += score`. Same thing. The longer version is sometimes clearer when you're learning, so I'm leaving it for now.

---

## Beat 5 — Print the answer [6:00 – 6:45]

> After the loop, we print the result.

```cpp
cout << "Total: " << total << endl;
```

> That's it. The whole program.

[ON SCREEN: scroll back up so the entire program is visible at once.]

> Twelve lines of actual logic. Let me run it.

---

## Beat 6 — Compile and run [6:45 – 9:00]

[ON SCREEN: terminal panel.]

> I'll save the file. Then in the terminal:

```
g++ -std=c++98 -Wall main.cpp -o quiz
```

> `-std=c++98` because that's what UP requires for COS 132. `-Wall` so the compiler warns me about anything dodgy. `-o quiz` so the executable is named `quiz` instead of the default `a.out`.

[Compile completes with no warnings.]

> No errors. Now:

```
./quiz
```

[Program prompts.]

> Let me put in five scores. 85... 72... 91... 68... 79.

[Total prints: 395.]

> 395. Let me check that quickly. 85 plus 72 is 157. Plus 91 is 248. Plus 68 is 316. Plus 79 is 395. Correct.

---

## Beat 7 — Test a different case [9:00 – 10:30]

> Let me run it again with different numbers, just to convince myself it works.

[Run again. Inputs: 100, 100, 100, 100, 100. Total: 500.]

> 500. Sanity check.

> What if I want to mark a different number of scripts? Say three? I just change `N`.

[Edit `const int N = 5;` to `const int N = 3;`. Recompile. Run. Enter 50, 60, 70. Total: 180.]

> The loop adapts because `N` is the only place the count is mentioned. That's the value of putting it in a named constant — change one thing, the rest follows.

---

## Beat 8 — What you'll do next [10:30 – 12:00]

[ON SCREEN: the final program.]

> So that's Plan A — read a known number of values — combined with what we'll later call Plan F — accumulate a running total. You'll see both of these patterns over and over, in much more complicated programs, all the way through to the exam. Today we just used them in their simplest form.

> Now your turn. Close this video. Open `starter/main.cpp`. Write this program from scratch. If you get stuck, finish what you can and mark where you got lost. Don't peek at the solution until you've made an honest attempt.

> When you're done, compile and run it. Compare against `solution/main.cpp`.

> Then, and this is the bit most students skip — re-watch only the part you got stuck on, close the video again, and write the program a second time. The second time is where it sticks.

> See you tomorrow. Day 2 we add a sentinel and find the highest score, instead of the total. Same kind of problem, two more patterns to add to your toolbox.

> Have a good one.

[End of video.]

---

## Notes for the recording

- **Mood**: calm, practical, slightly conversational. Not hype-y. Not lecturing.
- **Pace**: don't rush the loop section (Beat 4) — that's the conceptual core.
- **Re-shoots if needed**: Beat 6 (the compile/run) is the most likely place to need a second take if there's a typo.
- **Editing**: trim any "umm" or long pauses. Keep typing visible at full speed — students should be able to see the keystrokes.
- **Outro hook**: ending with "see you tomorrow" sets the daily-cadence expectation for the rest of the week.
