// Day 2 — Code with Swift — The Gym Tally (solution)
//
// Reads weights one at a time until the user enters -1.
// Reports the heaviest lift and the count of lifts above the threshold.
//
// Stage 2 architecture: function declarations above main, definitions below.

#include <iostream>
using namespace std;

// Function declarations
int updateMax(int currentMax, int newValue);
int incrementIfAbove(int currentCount, int value, int threshold);

int main() {
    const int SENTINEL = -1;
    const int THRESHOLD = 95;

    int weight;
    int heaviest = 0;
    int count = 0;

    cout << "Enter weights one at a time. -1 to stop." << endl;
    cout << "Weight: ";
    cin >> weight;

    while (weight != SENTINEL) {
        heaviest = updateMax(heaviest, weight);
        count = incrementIfAbove(count, weight, THRESHOLD);
        cout << "Weight: ";
        cin >> weight;
    }

    cout << "Heaviest: " << heaviest << endl;
    cout << "Personal bests (>" << THRESHOLD << "): " << count << endl;

    return 0;
}

// Function definitions
int updateMax(int currentMax, int newValue) {
    if (newValue > currentMax) {
        return newValue;
    }
    return currentMax;
}

int incrementIfAbove(int currentCount, int value, int threshold) {
    if (value > threshold) {
        return currentCount + 1;
    }
    return currentCount;
}
