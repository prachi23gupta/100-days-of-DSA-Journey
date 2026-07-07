#include <iostream>
using namespace std;

// /Equilibrium Index

int equilibriumIndex(int arr[], int n) {

    int totalSum = 0;

    // Calculate total sum
    for(int i = 0; i < n; i++)
        totalSum += arr[i];

    int leftSum = 0;

    for(int i = 0; i < n; i++) {

        totalSum -= arr[i];   // Now totalSum becomes rightSum

        if(leftSum == totalSum)
            return i;

        leftSum += arr[i];
    }

    return -1;
}

int main() {

    int arr[] = {1, 3, 5, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << equilibriumIndex(arr, n);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
