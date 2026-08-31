#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Removing Minimum and Maximum From Array

int minimumDeletions(vector<int>& nums) {
    int n = nums.size();

    int minIdx = min_element(nums.begin(), nums.end()) - nums.begin();
    int maxIdx = max_element(nums.begin(), nums.end()) - nums.begin();

    int left = max(minIdx, maxIdx) + 1;
    int right = n - min(minIdx, maxIdx);
    int both = min(minIdx, maxIdx) + 1 + n - max(minIdx, maxIdx);

    return min({left, right, both});
}

int main() {
    vector<int> nums = {2, 10, 7, 5, 4, 1, 8, 6};

    cout << minimumDeletions(nums) << endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
