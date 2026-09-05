#include <iostream>
#include <vector>
#include <algorithm>
using namespace std

// Smallest Stable Index II

int firstStableIndex(vector<int>& nums, int k) {
    int n = nums.size();

    // suffixMin[i] = minimum from i to n-1
    vector<int> suffixMin(n);
    suffixMin[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--) {
        suffixMin[i] = min(nums[i], suffixMin[i + 1]);
    }

    // Check from left to right
    int prefixMax = nums[0];

    for (int i = 0; i < n; i++) {
        prefixMax = max(prefixMax, nums[i]);

        if (prefixMax - suffixMin[i] <= k) {
            return i;
        }
    }

    return -1;
}

int main() {
    vector<int> nums = {5, 0, 1, 4};
    int k = 3;

    cout << firstStableIndex(nums, k);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
