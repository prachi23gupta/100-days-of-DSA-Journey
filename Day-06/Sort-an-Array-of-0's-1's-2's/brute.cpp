#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

    vector<int> arr = {2, 0, 2, 1, 1, 0};

    sort(arr.begin(), arr.end());

    for(int it : arr) {
        cout << it << " ";
    }

    return 0;
}


// Time Complexity = O(n log n)
// Space Complexity = O(1)
