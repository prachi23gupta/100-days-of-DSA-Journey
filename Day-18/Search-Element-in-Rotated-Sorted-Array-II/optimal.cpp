#include <iostream>
#include <vector>
using namespace std;

// Search Element in Rotated Sorted Array-II

bool search(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return true;
        }

        // Duplicates
        if (arr[start] == arr[mid] && arr[mid] == arr[end]) {
            start++;
            end--;
            continue;
        }

        // Left half sorted
        if (arr[start] <= arr[mid]) {

            if (target >= arr[start] && target < arr[mid]) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        // Right half sorted
        else {

            if (target > arr[mid] && target <= arr[end]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
    }

    return false;
}

int main() {
    vector<int> arr = {2, 5, 6, 0, 0, 1, 2};
    int target = 0;

    cout << search(arr, target);

    return 0;
}
