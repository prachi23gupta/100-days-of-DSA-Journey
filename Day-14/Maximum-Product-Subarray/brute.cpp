#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Maximum Product Subarray - subarray = contigous pat on an array

int main(){

    vector<int> arr = {2, 3, -2, 4, 5};
    int n = arr.size();

    int maxi = INT_MIN;

    for(int i = 0; i < n; i++){

        for(int j = i; j < n; j++){ // starting from i to inlude single subarray also
            int product = 1;
            
            for(int k = i; k <= j; k++){
                product *= arr[k];
            }
            maxi = max(maxi, product);
        }
    }
    cout << maxi << endl;

    return 0;
}

// Time Complexity: O(n^3)
// Space Complexity: O(1)
