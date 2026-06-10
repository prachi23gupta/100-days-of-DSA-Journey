#include <iostream>
#include <vector>
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

        if(ans.empty() || arr[i][0] > ans.back()[1]){
            ans.push_back(arr[i]); // if eg: 1, 3 and 7, 6 m se 7 > 3 h to no overlapping to current 1, 3 ko lelo
        }
        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    for(auto interval : ans){
        cout << "[" << interval[0] << ", " << interval[1] << "]" << endl;
    }

    return 0;
}


// Time Complexity: O(n log n + n) 
// // Space Complexity: O(n)
