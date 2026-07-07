#include <iostream>
using namespace std;

// Equilibrium Index

// BETTER SOLUTION

int equilibriumIndex(int arr[], int n) {

    int prefix[n];
    prefix[0] = arr[0];

    // Prefix Sum
    for(int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];

    int totalSum = prefix[n - 1];

    for(int i = 0; i < n; i++) {

        int leftSum = (i == 0) ? 0 : prefix[i - 1];
        int rightSum = totalSum - prefix[i];

        if(leftSum == rightSum)
            return i;
    }

    return -1;
}

int main() {

    int arr[] = {1, 3, 5, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << equilibriumIndex(arr, n);

    return 0;
}

// Time Complexity = O(n) + O(n) = O(2n)
// Space Complexity = O(n)
