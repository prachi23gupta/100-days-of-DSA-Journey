#include <iostream>
#include <vector>
using namespace std;

// Binary Search - array is sorted find the target given

int main() {

    vector<int> nums = {1, 2, 3, 9, 19, 34};

    int n = nums.size();
    int start = 0;
    int end = n - 1;

    int target;
    cout << "Enter target: ";
    cin >> target;

    while (start <= end) {

        int mid = start + (end - start) / 2;

        if (nums[mid] == target) {
            cout << "Found at index: " << mid << endl;
            return 0;
        }
        else if (nums[mid] > target) {
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    cout << "Not Found" << endl;

    return 0;
}

// Time Complexity: O(log2 n)
// Space Complexity: O(1)
