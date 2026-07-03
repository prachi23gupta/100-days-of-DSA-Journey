#include <iostream>
#include <vector>
using namespace std;

// Shuffle the Array

vector<int> shuffle(vector<int>& nums, int n){

    vector<int> ans;

    for(int i = 0; i < n; i++){
        ans.push_back(nums[i]);
        ans.push_back(nums[i + n]);
    }

    return ans;
}

int main(){

    vector<int> nums = {2,5,1,3,4,7};
    int n = 3;

    vector<int> ans = shuffle(nums, n);

    for(int x : ans){
        cout << x << " ";
    }

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
