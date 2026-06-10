#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Merge Overlapping Intervals

int main(){

    vector<vector<int>> arr = {
    {1,3},
    {2,6},
    {8,9},
    {9,11},
    {8,10},
    {2,4},
    {15,18},
    {16,17}
};

    int n = arr.size();

    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    
    for(int i = 0; i < n; i++){

        int start = arr[i][0]; // eg: {1, 3} ka 1
        int end = arr[i][1]; // eg: {1, 3} ka 3

        if(!ans.empty() && end <= ans.back()[1]){ // if ans array is not empty and eg: {1, 6} was already stored then current end <= 6
            continue; // eg: {2, 6} will get continued
        }

        for(int j = i + 1; j < n; j++){
            if(arr[j][0] <= end){ // eg: if first element of {2, 6} is <= second element of {1, 3}
                end = max(end, arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start, end});
    }

    for(auto interval : ans){
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }

    return 0;
}

// Time Complexity: O(n log n + 2n) // not n^2 because we are not going to every array and also breaking and continuing
// Space Complexity: O(n)
