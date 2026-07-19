#include <iostream>
using namespace std;

// First Bad Version

bool isBadVersion(int version) {
    int firstBad = 4;   // Example
    return version >= firstBad;
}

int firstBadVersion(int n) {
    int start = 1;
    int end = n;
    int ans = n;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (isBadVersion(mid)) {
            ans = mid;
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }

    return ans;
}

int main() {
    int n = 5;

    cout << "First Bad Version: " << firstBadVersion(n);

    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)
