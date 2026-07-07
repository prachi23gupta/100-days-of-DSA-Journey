#include <iostream>
using namespace std;

// Equilibrium Index

// BRUTE FORCE

int equilibriumIndex(int arr[], int n) {

    for(int i = 0; i < n; i++) {

        int leftSum = 0;
        int rightSum = 0;

        // Calculate Left Sum
        for(int j = 0; j < i; j++)
            leftSum += arr[j];

        // Calculate Right Sum
        for(int j = i + 1; j < n; j++)
            rightSum += arr[j];

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

// Time Complexity = O(n²)
// Space Complexity = O(1)
