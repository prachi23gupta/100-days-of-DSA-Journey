#include <iostream>
using namespace std;

// Arranging Coins

int arrangeCoins(int n) {

    long long low = 0;
    long long high = n;

    while (low <= high) {

        long long mid = low + (high - low) / 2;

        long long coins = mid * (mid + 1) / 2;

        if (coins == n)
            return mid;

        else if (coins < n)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return high;
}

int main() {

    int n = 8;

    cout << arrangeCoins(n);

    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)
