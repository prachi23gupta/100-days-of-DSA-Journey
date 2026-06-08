#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
using namespace std;

// 3 Sum
// print all unique triplets whose sum = 0

int main(){

    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();

    set<vector<int>> st;

    for(int i = 0; i < n; i++){

        unordered_set<int> hashSet;

        for(int j = i + 1; j < n; j++){

            int third = -(arr[i] + arr[j]);

            if(hashSet.find(third) != hashSet.end()){

                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());

                st.insert(temp);
            }

            hashSet.insert(arr[j]);
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

// Time Complexity: O(N^2 * logM)
// Space Complexity: O(N + M)
