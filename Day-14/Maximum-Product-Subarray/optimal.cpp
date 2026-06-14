// Hard one

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Maximum Product Subarray

/*
1. Even number of negatives → whole segment may give maximum product.

2. Odd number of negatives → remove either the leftmost negative side
   or the rightmost negative side. Because beech se shuru kia to max ni mil payega

3. Prefix scan captures one possibility.

4. Suffix scan captures the other possibility.

5. Zero breaks the segment, so restart product from 1.

if for -2, 3, 4, -1, 0, -2, 3, 1, 4, 0, 4, 6, -1, 4 to isme hm -2 se -1 ka then next -2 se 4 tk fir 4 se 4 tk ka dekhege condition is agr 0 aa jaye to prefix = 1 kyuki ab hm newly start krege
*/

int main() {

    vector<int> arr = {2, 3, -2, 4, 5};
    int n = arr.size();

    int ans = INT_MIN;
    int prefix = 1;
    int suffix = 1;

    for(int i = 0; i < n; i++) {

        if(prefix == 0) prefix = 1;
        if(suffix == 0) suffix = 1;

        prefix *= arr[i];
        suffix *= arr[n - i - 1];

        ans = max(ans, max(prefix, suffix));
    }

    cout << ans << endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
