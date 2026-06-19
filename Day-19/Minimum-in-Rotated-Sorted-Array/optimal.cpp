#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Minimum in rotated sorted array
// by using this way we will be left with only one index which is gonna store in start

int main(){

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int n = arr.size();

    int start = 0;
    int end = n - 1;
    int minimum = INT_MAX;
    int mid = -1;

    while(start <= end){
        mid = start + ((end - start) / 2);

        if(arr[mid] > arr[end]){
            start = mid + 1;
        }
        else{
            end = mid; // otherwise we are throwing mid without consideration
        }
    }
    cout << arr[start];

    return 0;
}

// Time Complexity: O(log n) // base 2
// Space Complexity: O(1)

