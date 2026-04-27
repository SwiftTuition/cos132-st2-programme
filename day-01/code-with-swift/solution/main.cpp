// Day 1 — Code with Swift — Total the Quiz Scores (solution)
//
// Reads five quiz scores, one at a time, and prints the total at the end.
// Stage 1 architecture: everything in main(), no helper functions.

#include <iostream>
using namespace std;

int main() {
    const int N = 5;
    int total = 0;
    int score;

    cout << "Enter " << N << " quiz scores:" << endl;

    for (int i = 1; i <= N; i++) {
        cout << "Score " << i << ": ";
        cin >> score;
        total = total + score;
    }

    cout << "Total: " << total << endl;

    return 0;
}
