#include <iostream>
using namespace std;

// Find Smallest Letter Greater Than Target

char nextGreatestLetter(char arr[], int n, char target) {

    int low = 0;
    int high = n - 1;

    while(low <= high) {

        int mid = low + (high - low) / 2;

        if(arr[mid] <= target)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return arr[low % n];
}

int main() {

    char arr[] = {'c', 'f', 'j'};
    int n = sizeof(arr) / sizeof(arr[0]);

    char target = 'd';

    cout << nextGreatestLetter(arr, n, target);

    return 0;
}

// Time Complexity = O(log n)
// Space Complexity = O(1)
