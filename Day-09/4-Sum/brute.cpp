#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

// 4 Sum
// print all unique vectors whose sum = target
// but duplicate array is not allowed
// print in a sorted manner

int main(){

    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int n = arr.size();

    int target = 0;
    set<vector<int>> st;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                for(int l = k + 1; l < n; l++){
                    if(arr[i] + arr[j] + arr[k] + arr[l] == target ){

                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());

                        st.insert(temp);
                    }
                }
            }
        }
    }

    for(auto it : st){
        for(auto x : it){
            cout << x << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(N^4 * logM)
// Space Complexity: O(M)

// M is the number of unique vector stored in the set.
