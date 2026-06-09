#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 4 Sum (Optimal)
// print all unique quadruplets whose sum = target

int main() {

    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int target = 1;

    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for (int i = 0; i < n; i++) {

        // skip duplicates for i
        if (i > 0 && arr[i] == arr[i - 1]) continue;

        for (int j = i + 1; j < n; j++) {

            // skip duplicates for j
            if (j > i + 1 && arr[j] == arr[j - 1]) continue;

            int left = j + 1;
            int right = n - 1;

            while (left < right) {

                long long sum = (long long)arr[i] +
                                arr[j] +
                                arr[left] +
                                arr[right];

                if (sum < target) {
                    left++;
                }
                else if (sum > target) {
                    right--;
                }
                else {

                    ans.push_back(
                        {arr[i], arr[j], arr[left], arr[right]}
                    );

                    left++;
                    right--;

                    // skip duplicates for left
                    while (left < right &&
                           arr[left] == arr[left - 1]) {
                        left++;
                    }

                    // skip duplicates for right
                    while (left < right &&
                           arr[right] == arr[right + 1]) {
                        right--;
                    }
                }
            }
        }
    }

    for (auto it : ans) {
        for (auto x : it) {
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(n^3)
// Space Complexity: O(1) (excluding output array)
