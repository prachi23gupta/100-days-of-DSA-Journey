#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// Longest Consecutive sequence
// give the length of longest consecutiven sequence

int main(){

    vector <int> arr = {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2};
    int n = arr.size();
    int count = 1;
    int maxLen = 1;

    sort(arr.begin(), arr.end());

    for(int i = 1; i < n; i++){

        if(arr[i] == arr[i - 1] + 1){
            // duplicate
        }
        else if( arr[i] == arr[i - 1] + 1){
            count++;
        }
        else{
            maxLen = max(maxLen, count);
            count = 1;
        }
    }

    maxLen = max(maxLen, count);

    cout << maxLen << endl;

    return 0;
}

// Time Complexity: O(n log n) + O(n) = O(n log n)
// Space Complexity: O(1);
