#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Add Binary

string addBinary(string a, string b) {
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0;

    string ans;

    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;

        if (i >= 0)
            sum += a[i--] - '0';

        if (j >= 0)
            sum += b[j--] - '0';

        ans += char('0' + (sum % 2));
        carry = sum / 2;
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    string a, b;
    cin >> a >> b;

    cout << addBinary(a, b);

    return 0;
}

// Time Complexity: O(max(n, m))
// Space Complexity: O(max(n, m))
