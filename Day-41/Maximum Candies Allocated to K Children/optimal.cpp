#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Maximum Candies Allocated to K Children

bool canAllocate(vector<int>& candies, long long k, int mid) {
    long long count = 0;

    for (int candy : candies)
        count += candy / mid;

    return count >= k;
}

int maximumCandies(vector<int>& candies, long long k) {
    int low = 1;
    int high = *max_element(candies.begin(), candies.end());
    int ans = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(candies, k, mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return ans;
}

int main() {
    vector<int> candies = {5, 8, 6};
    long long k = 3;

    cout << maximumCandies(candies, k);

    return 0;
}

// Time Complexity: O(n log M)
// Space Complexity: O(1)
