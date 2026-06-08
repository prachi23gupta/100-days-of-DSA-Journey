#include <iostream>
#include <vector>
#include <set>
using namespace std;

// 3 Sum
// print all unique triplets whose sum = 0

int main(){

    vector<int> arr = {-1, 0, 1, 2, -1, -4};
    int n = arr.size();

    set<vector<int>> st;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){

                if(arr[i] + arr[j] + arr[k] == 0){

                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());

                    st.insert(temp);
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

// Time Complexity: O(N^3 * logM)
// Space Complexity: O(M)
