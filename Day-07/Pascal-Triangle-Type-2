#include <iostream>
using namespace std;

// Pascal Triangle
// given n print that entire row

int main(){

    int n;

    cout << "Enter the value of n: ";
    cin >> n; // row

    long long ans = 1; // to prevent overflow

    cout << ans << " ";

    for(int i = 1; i < n; i++) {
        ans = ans * (n - i);
        ans = ans / (i);
        cout << ans << " ";
    }

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)

// other method is by using formula which is brute force of this
