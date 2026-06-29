#include <iostream>
#include <vector>
using namespace std;

// Move Zeroes to End

///BRUTE - FORCE SOLUTION

// 1. store all the non-zero elements in an array
// 2. then put these elements in original array but starting from 0 to size of other array index
// 3. put all the zeros now at last

vector<int> moveZeroes(vector<int> &a) {

    int n = a.size();

    // Step 1: Store all non-zero elements in temp vector
    vector<int> temp;

    for (int i = 0; i < n; i++) {
        if (a[i] != 0) {
            temp.push_back(a[i]);
        }
    }

    // Step 2: Copy non-zero elements back to original array
    int nz = temp.size();

    for (int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }

    // Step 3: Fill remaining places with zeros
    for (int i = nz; i < n; i++) {
        a[i] = 0;
    }

    return a;
}

int main() {

    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    arr = moveZeroes(arr);

    cout << "Array after moving zeroes: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
// Time complexity = O(2n)
// Space complexity = O(nlogn)
