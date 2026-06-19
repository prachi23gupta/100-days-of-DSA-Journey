#include <iostream>
#include <vector>
using namespace std;

// Find how many times the array has been rotated

int main(){

    vector<int> arr = {4, 5, 6, 7, 0, 1, 2};
    int n = arr.size();

    int start = 0;
    int end = n - 1;

    while(start < end){
        int mid = start + ((end - start) / 2);

        if(arr[mid] > arr[end]){
            start = mid + 1;
        }
        else{
            end = mid;
        }
    }

    cout << start;   // number of rotations

    return 0;
}

// Time Complexity: O(log n) // base 2
// Space Complexity: O(1)
