#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Check if N and its double exists

bool checkIfExist(vector<int>& arr) {

    sort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {

        int target = 2 * arr[i];
        int start = 0;
        int end = arr.size() - 1;

        while (start <= end) {

            int mid = start + (end - start) / 2;

            if (arr[mid] == target) {
                if (mid != i)
                    return true;
                break;
            }
            else if (arr[mid] < target) {
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

    vector<int> arr = {10, 2, 5, 3};

    if (checkIfExist(arr))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(1)
