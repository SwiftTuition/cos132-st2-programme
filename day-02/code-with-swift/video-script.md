# Day 2 — Code with Swift — Video Script

**Scenario:** The Gym Tally
**Architecture:** Stage 1 → 2 — single file, function declarations above `main`, definitions below
**Length:** ~14 minutes
**Audience:** COS 132 students on Day 2 of the ST2 programme

This is the speaking script for the video, beat by beat. Read it as a guide, not as a fixed line-by-line. Bracketed text is stage direction; un-bracketed text is what Swift says on camera.

---

## Beat 1 — Hook [0:00 – 1:15]

[ON SCREEN: a blank VS Code window with `main.cpp` empty in the editor.]

> Good day, good people. Welcome to Day 2 of Code with Swift.

> Yesterday we totalled the quiz scores. Today, Caleb has a request. He has been logging his weights at the gym, and he is sick of doing the maths himself. He wants a program that asks for one weight at a time, stops when he enters `-1`, and tells him two things: what was the heaviest lift, and how many of those lifts were above 95 kilograms — his "personal bests".

> So that is the brief. The brief comes from a real human who wants the answer. We just have to give them the program.

> What do we need to do?

[Pause.]

> One: read weights one at a time. We do not know how many. Caleb might do five sets, he might do twelve. We need a loop that keeps going until he enters the special sentinel value, `-1`. That is Plan C from Lecture 17 — read an unknown number of values until a sentinel.

> Two: track the heaviest. As each weight comes in, we compare it to the heaviest we have seen so far, and if the new one is bigger, we update. That is Plan G — find the largest.

> Three: count personal bests. Each time a weight is greater than 95, we bump a counter. That is Plan E — count values matching a condition.

> Three plans, all running side by side inside one loop. Yesterday we composed two plans. Today we compose three. And we are going to introduce something new to keep the code organised — we are going to write our own helper functions.

---

## Beat 2 — Set up the file [1:15 – 2:30]

[ON SCREEN: typing into `main.cpp`.]

> First, the iostream include and the namespace, same as last time.

```cpp
#include <iostream>
using namespace std;
```

> Now, today we are going Stage 2 — that means I am going to write two helper functions below `main`, and **declare them up here**, before `main`. The declaration tells the compiler "these functions exist, here are their signatures, the bodies come later."

> One function will update the maximum: it takes the current max and a new value, and returns whichever is bigger. The other will conditionally increment a count: it takes the current count, the value, and a threshold, and returns the count plus one if the value is above the threshold, or the count unchanged otherwise.

> Let me write the prototypes:

```cpp
int updateMax(int currentMax, int newValue);
int incrementIfAbove(int currentCount, int value, int threshold);
```

> Now I can write `main` knowing the compiler will accept calls to those two functions, even though their bodies come later in the file.

```cpp
int main() {

    return 0;
}
```

---

## Beat 3 — Set up the variables [2:30 – 4:00]

[ON SCREEN: cursor inside main.]

> Inside `main` I need a few things.

> First, two constants. The sentinel value (`-1`) and the threshold (`95`). Putting them in named constants makes the code clearer and easier to change later. If Caleb decides his personal-best threshold is now `100`, I change one number.

```cpp
const int SENTINEL = -1;
const int THRESHOLD = 95;
```

> Then three variables: a place to read each weight into, a place to track the heaviest so far, and a place to count personal bests.

```cpp
int weight;
int heaviest = 0;
int count = 0;
```

> Notice `heaviest` and `count` are initialised to zero. Plan E and Plan G both need this. If I left `heaviest` uninitialised, my program would compare new weights against garbage memory, and the answer would be wrong. If I left `count` uninitialised, the count would start at some random number.

> `weight` does not need an initial value because the very first thing I am going to do with it is read into it.

---

## Beat 4 — The first read and the loop [4:00 – 7:30]

> Now the input prompt. Tell the user what to do.

```cpp
cout << "Enter weights one at a time. -1 to stop." << endl;
```

> Then read the first weight. This is the Plan C pattern: **read once before the loop**, then **read again at the end of each loop body**, then check the condition.

```cpp
cout << "Weight: ";
cin >> weight;
```

> Now the loop itself. While the weight is not the sentinel, we do the work and then read the next one.

```cpp
while (weight != SENTINEL) {

    cin >> weight;
}
```

> Inside, two things happen. We update the maximum, and we conditionally increment the count.

```cpp
while (weight != SENTINEL) {
    heaviest = updateMax(heaviest, weight);
    count = incrementIfAbove(count, weight, THRESHOLD);
    cout << "Weight: ";
    cin >> weight;
}
```

> Look carefully at the order. Inside the loop body:
> 1. Update the max.
> 2. Update the count.
> 3. Prompt for the next weight.
> 4. Read the next weight.

> Then control jumps back up and the condition is checked again. If the new weight is `-1`, the loop exits. The sentinel itself is never processed — neither the max nor the count is updated for it. That is exactly how Plan C is supposed to work.

> Notice I am calling functions I have not yet defined. The prototypes at the top let the compiler accept this.

---

## Beat 5 — The report [7:30 – 8:30]

> After the loop, print the report.

```cpp
cout << "Heaviest: " << heaviest << endl;
cout << "Personal bests (>" << THRESHOLD << "): " << count << endl;
```

> Two lines. The second one prints the threshold value too, so the report is self-explanatory: a reader does not need to know that `95` was hard-coded somewhere; the output tells them.

---

## Beat 6 — The helper functions [8:30 – 11:00]

> Now the bodies of the two helper functions, after `main`.

```cpp
int updateMax(int currentMax, int newValue) {
    if (newValue > currentMax) {
        return newValue;
    }
    return currentMax;
}
```

> If the new value is bigger, return it. Otherwise return the existing max unchanged. The `if` only has one branch — there is no `else`, because a `return` inside the `if` already exits the function.

> Some of you might write it with an `else`:
> ```cpp
> if (newValue > currentMax) {
>     return newValue;
> } else {
>     return currentMax;
> }
> ```
> That is also correct. Both versions produce the same machine code. Pick whichever you find clearer.

> The second function is similar:

```cpp
int incrementIfAbove(int currentCount, int value, int threshold) {
    if (value > threshold) {
        return currentCount + 1;
    }
    return currentCount;
}
```

> If the value is above the threshold, return the count plus one. Otherwise return the count unchanged. Again, two paths, same shape as `updateMax`.

> Why bother with helper functions? Two reasons. One: the names tell the reader what is happening. `heaviest = updateMax(heaviest, weight);` is easier to read than the equivalent `if/else` block inline. Two: if I wanted to change how the max is calculated (say, count ties differently), I change it in one place.

> This is the start of Stage 2. From here on, you will see more programs that split work into helpers like this. Stage 3 will go further — it will put the helpers in a separate `.cpp` file with a header, but that is later in the week.

---

## Beat 7 — Compile and run [11:00 – 13:00]

[ON SCREEN: terminal panel.]

> Save the file. Then in the terminal:

```
g++ -std=c++98 -Wall main.cpp -o gym
```

> Standard flags, same as yesterday. The `-o gym` names the executable `gym` instead of the default `a.out`.

[Compile completes with no warnings.]

> No errors. Now run it.

```
./gym
```

[Program prompts: "Enter weights one at a time. -1 to stop." then "Weight: ".]

> Let me put in five weights. 80... 100... 120... 90... and then `-1` to stop.

[Output:
```
Heaviest: 120
Personal bests (>95): 2
```]

> 120 is the heaviest. Personal bests above 95: 100 and 120, so two. Correct.

> Let me try one more case. What if Caleb has a really good day and beats himself every set?

[Re-run. Inputs: 100, 110, 120, 130, -1. Output: Heaviest 130, Personal bests 4.]

> Four personal bests, max 130. Looks good.

> Edge case: what if he gives up after the first weight?

[Re-run. Inputs: 90, -1. Output: Heaviest 90, Personal bests 0.]

> 90 is below the threshold, so zero personal bests. The max is still tracked correctly. The Plan G initialisation to `0` works here because no real weight is below `0`. If Caleb were tracking, say, temperature, that initialisation would be wrong and we would need to start `heaviest` differently. Watch for that in your own code.

---

## Beat 8 — Wrap [13:00 – 14:00]

> So that was Plans C, E, and G — three of the eight plans from Lecture 17 — composed in one program. Plus your first taste of helper functions: declare above, define below. That is Stage 2.

> Now your turn. Close this video. Open `starter/main.cpp`. Write this program from scratch. Then compile, run, and compare against the solution.

> The next part — the part most students skip — is to do it again. Re-watch only the bit you got stuck on, close the video, and write the program a second time from a blank file. The second time is where it sticks.

> Tomorrow, Day 3, we go into recursion. Same kinds of problems we have been solving with loops, but the loop becomes a function calling itself. It will feel weird at first. That is okay.

> Have a good one.

[End of video.]

---

## Notes for the recording

- **Mood**: same as Day 1 — calm, practical, slightly conversational. Today's "Caleb wants this" framing is the entry; lean into the cast.
- **Pace**: don't rush Beat 4 (the loop) — that is the conceptual core. The shape of Plan C is what we want students to internalise.
- **Re-shoots if needed**: Beat 6 (the helper function bodies) is small but easy to typo. A second take if a parameter name is wrong is fine.
- **Editing**: trim "umm" and long pauses. Keep typing visible at full speed.
- **Outro hook**: the "tomorrow we go into recursion" preview sets up Day 3.
