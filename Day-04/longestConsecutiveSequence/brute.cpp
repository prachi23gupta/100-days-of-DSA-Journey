#include <iostream>
#include <vector>
using namespace std;

// Longest Consecutive sequence
// give the length of longest consecutiven sequence

bool linearSearch(vector<int>& arr, int target){
    int n = arr.size();
    for(int j = 0; j < n; j++){
        if(arr[j] == target){
            return 1;
        }
    }
    return 0;
}

int main(){

    vector <int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    int n = arr.size();
    int maxLen = 0;

    for(int i = 0; i < n; i++){
        int current = arr[i];
        int count = 1;

        while(linearSearch(arr, current + 1)){
            current++;
            count++;
        }

        maxLen = max(maxLen, count);
    }

    cout << maxLen << endl;

    return 0;
}

// Time Complexity: O(n^3) in worst case othewise O(n^2)
// Space Complexity: O(1)
