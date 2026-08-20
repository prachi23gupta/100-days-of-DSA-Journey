#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 3 Sum
// print all unique triplets whose sum = 0

int main(){

    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();

    sort(arr.begin(), arr.end());

    vector<vector<int>> ans;

    for(int i = 0; i < n; i++){

        if(i > 0 && arr[i] == arr[i - 1]) continue;

        int j = i + 1;
        int k = n - 1;

        while(j < k){

            int sum = arr[i] + arr[j] + arr[k];

            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{

                ans.push_back({arr[i], arr[j], arr[k]});

                j++;
                k--;

                while(j < k && arr[j] == arr[j - 1]) j++;
                while(j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }

    for(auto it : ans){
        for(auto x : it){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(N^2)
// Space Complexity: O(1)   // ignoring output array
