#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Sort an Array of 0s, 1s and 2s (Brute Force)

int main() {

    vector<int> arr = {2, 0, 2, 1, 1, 0};

    sort(arr.begin(), arr.end());

    for (int x : arr) {
        cout << x << " ";
    }

    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(1)
