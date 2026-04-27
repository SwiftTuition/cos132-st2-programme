# Swift's ST2 Programme for COS 132

Good day, good people. This is the public repository for **Swift Tuition's seven-day self-paced run-up to ST2** in COS 132 at UP.

The programme is free, open, and built around three tracks:

- **Code with Swift** — short reproduction-drill videos (one per day) where I write a small program from scratch and explain every line. You watch, close the video, and write the same program from a blank file.
- **Pracs** — three escalating practical assignments. Each one drops in this repo on its scheduled day. You implement, run the local grader, iterate.
- **Mock Tests** — fifteen exam-difficulty written tests organised by unit. Each one comes with a worked-solution memo.

The programme runs from **27 April to 3 May 2026**, but the materials stay open after that. Use them at your own pace.

---

## Open in GitHub Codespaces

The fastest way to use the pracs is to open this repo in Codespaces. The C++ toolchain is pre-installed.

1. Click the green **Code** button at the top of this page.
2. Click the **Codespaces** tab.
3. Click **Create codespace on main**.

After about 30 seconds you'll be in a browser-based VS Code with `g++` ready to compile.

If you'd rather work locally: clone the repo, install `g++`, and you're set. The `.devcontainer/devcontainer.json` here also works with the VS Code Dev Containers extension on your own machine.

---

## How the repo is laid out

```
cos132-st2-programme/
├── programme/
│   └── index.html              <- the seven-day overview page (open in any browser)
├── day-01/
│   ├── README.md
│   ├── mock-test/              <- Foundations Test #1 + memo
│   ├── code-with-swift/        <- Day 1 video reproduction (quiz scores)
│   └── prac/                   <- Practical 1: The Study Squad Tracker
├── day-02/
│   ├── README.md
│   └── mock-test/              <- Foundations Test #2 + memo
├── day-03/
│   └── ...
└── ...
```

Each day folder has its own README explaining what's in it and what you should do that day. The materials build up across the week — by Day 7, every prac, every video, and every mock test sits in its day folder.

The programme overview page (`programme/index.html`) gives you the full seven-day plan at a glance and links back to each day. Open it in any browser.

---

## What's on the schedule

| Day | Date | What lands |
|---|---|---|
| 1 | Mon 27 Apr | Foundations Test #1, Code with Swift Day 1, Prac 1 drops |
| 2 | Tue 28 Apr | Foundations Test #2, Code with Swift Day 2, Unit G #1 |
| 3 | Wed 29 Apr | Foundations Test #3, Code with Swift Day 3, Unit G #2 |
| 4 | Thu 30 Apr | Code with Swift Day 4, Unit H #1, Prac 2 drops |
| 5 | Fri 1 May | Code with Swift Day 5, Unit H #2, Prac 3 drops |
| 6 | Sat 2 May | Code with Swift Day 6, Unit H #3 / Unit I #1, live Q&A |
| 7 | Sun 3 May | Code with Swift Day 7 (ST2 walkthrough), Comprehensive #1, live ST2 solve |

Materials drop progressively. Anything dated for a future day appears in this repo on that day.

---

## Working with a prac

Every prac follows the same flow:

1. Open `day-XX/prac/` in Codespaces.
2. Read `prac.md` for the full specification.
3. Open `starter/` and edit the `.cpp` files inside. Implement the function bodies.
4. Run `./grade.sh` from inside `starter/`. The grader compiles your code, runs every test, and prints a pass/fail report with marks.
5. Iterate until you're happy with your score.
6. (Optional, only after attempting) read `memo.md` for the worked-solution walkthrough.

There is no submission step. Your grader output is the score. Run it as often as you like.

---

## A note about the cast

The pracs feature recurring characters — **Caleb**, **Yolisa**, **Sahana** and **Swift**. They're real people from Swift Tuition's premium group. The running gags (Caleb calling Swift "Uncle", Yolisa caring about exact formatting, Sahana tracking attendance) come from real sessions. Take the work seriously, but not too seriously.

---

## Questions, bugs, suggestions

Open an issue on this repo or message Swift directly. The programme is being built incrementally — feedback during the week genuinely shapes what gets added.

Get to it.
