#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Maximum Product of Three Numbers

int maximumProduct(vector<int>& nums)
{
    sort(nums.begin(), nums.end());

    int n = nums.size();

    return max(nums[0] * nums[1] * nums[n - 1],
               nums[n - 1] * nums[n - 2] * nums[n - 3]);
}

int main()
{
    vector<int> nums = {-10, -10, 5, 2};

    cout << "Maximum Product: " << maximumProduct(nums);

    return 0;
}

/*
Time Complexity: O(n log n)
Space Complexity: O(1)
*/
