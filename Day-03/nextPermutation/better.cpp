#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// better
// using STL

int main(){

    vector<int> arr = {1, 2, 5, 4, 3};

    next_permutation(arr.begin(), arr.end());

    for(int x : arr){
        cout << x << " ";
    }

    cout << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
