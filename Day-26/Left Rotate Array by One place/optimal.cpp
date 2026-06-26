#include <iostream>
using namespace std;

// Left Rotate Array by one place

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7};

    int n = sizeof(arr) / sizeof(arr[0]);

    int temp = arr[0];
    for(int i = 1; i < n; i++){
        arr[i-1] = arr[i];
    }
    arr[n-1] = temp;

    for(int j = 0; j < n; j++){
        cout << arr[j] << " ";
    }

    return 0;
}

// Time Complexity	= O(n)
// Space Complexity = O(1) //tell the. interviewer if we say what is the extra space so according to it space comp is O(1) but if we consider the given array's space then it is O(N)
