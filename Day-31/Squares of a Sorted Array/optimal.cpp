#include <iostream>
#include <vector>
using namespace std;

// Squares of a Sorted Array

vector<int> sortedSquares(vector<int>& nums) {

    int n = nums.size();
    vector<int> ans(n);

    int left = 0;
    int right = n - 1;
    int index = n - 1;

    while (left <= right) {

        if (abs(nums[left]) > abs(nums[right])) {
            ans[index--] = nums[left] * nums[left];
            left++;
        }
        else {
            ans[index--] = nums[right] * nums[right];
            right--;
        }
    }

    return ans;
}

int main() {

    vector<int> nums = {-7, -3, 2, 3, 11};

    vector<int> ans = sortedSquares(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}


// Time Complexity: O(n)
// Space Complexity: O(n)
