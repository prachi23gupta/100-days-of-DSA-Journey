#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Find the missing and repeating number
// given an array of n size
// arr = {4, 3, 6, 2, 1, 1} so here 5 is missing and 1 is repeating so return both

int main(){

    vector <int> arr = {4, 3, 6, 2, 1, 1};
    int n = arr.size();

    unordered_map <int, int> mpp;
    
    for(int i = 0; i < n; i++){
        mpp[arr[i]]++;
        if(mpp[arr[i]] > 1){
            cout << "duplicate number is: " << arr[i] << endl;
        }
    }

    for(int i = 1; i <= n; i++){
        if(mpp[i] == 0){
            cout << "missing number is: " << i << endl;
            break;
        }
    }

    return 0;
}

// Time Complexity: O(2n) = approx O(n)
// Space Complexity: O(n)
