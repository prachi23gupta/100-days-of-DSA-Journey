#include <iostream>
#include <algorithm>
#include <set>
#include <unordered_set>
using namespace std;

int main(){

    vector<int> arr = {1, 0, -1, 0, -2, 2};
    int n = arr.size();

    int target = 1;
    set <vector<int>> st;

    for(int i = 0; i < n; i++){

        for(int j = i + 1; j < n; j++){ // we fixed i and j for now

            unordered_set <int> hashSet;

            for(int k = j + 1; k < n; k++){

                int fourth = target -(arr[i] + arr[j] + arr[k]);

                if(hashSet.find(fourth) != hashSet.end()){

                    vector<int> temp = {arr[i], arr[j], arr[k], fourth};
                    sort(temp.begin(), temp.end());

                    st.insert(temp);
                }

                hashSet.insert(arr[k]);
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

// Time Complexity: O(n^3 * log m)
// Space Complexity: O(n + m)
