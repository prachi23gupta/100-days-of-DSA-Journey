#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// optimal

// leaders in array = every element on right side of that particulr element should be smaller
// multiple leaders can be there

int main(){

    vector <int> array = {10, 22, 12, 3, 0, 6};
    vector <int> ans = {};
    int n = array.size();
    int maxi = INT_MIN;

    for(int i = n - 1; i >= 0; i--){
        if(array[i] > maxi){
            ans.push_back(array[i]);
            maxi = array[i];
        }
    }

    reverse(ans.begin(), ans.end());

    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
