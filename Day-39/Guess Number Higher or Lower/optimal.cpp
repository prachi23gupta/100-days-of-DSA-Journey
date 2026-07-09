#include <iostream>
using namespace std;

// Guess Number Higher or Lower

int picked = 67;   // Number to be guessed

int guess(int num) {
    if (num == picked)
        return 0;
    else if (num > picked)
        return -1;
    else
        return 1;
}

int guessNumber(int n) {
    int low = 1, high = n;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        int ans = guess(mid);

        if (ans == 0)
            return mid;
        else if (ans == -1)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1;
}

int main() {
    int n = 100;

    cout << "Guessed Number = " << guessNumber(n);

    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)
