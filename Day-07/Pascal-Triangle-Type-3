#include <iostream>
using namespace std;

// Pascal Triangle
// given n print the entire triangle

int main(){

    int n;

    cout << "Enter the value of n: ";
    cin >> n; // row

    long long ans = 1; // to prevent overflow

    for(int row = 1; row <= n; row++) {

        long long ans = 1;
        cout << ans << " ";

        for(int col = 1; col < row; col++) {
            ans = ans * (row - col);
            ans = ans / col;
            cout << ans << " ";
        }

        cout << endl;
    }

    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)

// its brute-force will be tc: n^3 when we fill pass func in second loop as func will also have a loop
