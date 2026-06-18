#include <iostream>
#include <vector>
using namespace std;

// Search element in rotated sorted array

int search(vector<int>& arr, int target) {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (arr[mid] == target) {
            return mid;
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

    return -1;
}

int main() {
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    cout << search(arr, target);

    return 0;
}
