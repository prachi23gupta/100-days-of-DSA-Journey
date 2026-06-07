#include <iostream>
using namespace std;

// Pascal Triangle
// given R and C print the element with that R and C number

// approach - (R - 1) C (C - 1) OR nCr
// where n = R - 1 and c - C - 1
// but for less TC we just multiple r times 7C2 m 7*6 tk hi 2 bar hi esa

int main(){

    int R, C;

    cout << "Enter the value of R: ";
    cin >> R;

    cout << "Enter the value of C: ";
    cin >> C;

    long long ans = 1; // to prevent overflow

    int n = R - 1;
    int r = C - 1;

    for(int i = 0; i < r; i++) {
        ans = ans * (n - i);
        ans = ans / (i + 1);
    }

    cout << ans << endl;

    return 0;
}

// Time Complexity: O(C - 1)
// Space Complexity: O(1)
