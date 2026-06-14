#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Maximum Product Subarray

int main(){

    vector<int> arr = {2, 3, -2, 4, 5};
    int n = arr.size();

    int maxi = INT_MIN;

    for(int i = 0; i < n; i++){
        int product = 1

        for(int j = i; j < n; j++){ // starting from i to inlude single subarray also    
            product *= arr[j];
            maxi = max(maxi, product);
        }
    }
    cout << maxi << endl;

    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
