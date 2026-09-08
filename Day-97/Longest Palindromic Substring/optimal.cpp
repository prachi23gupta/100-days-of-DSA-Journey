#include <iostream>
#include <string>
using namespace std;

// Longest Palindromic Substring

string longestPalindrome(string s) {
    int n = s.length();
    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {

        // Odd length
        int l = i, r = i;

        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--;
            r++;
        }

        // Even length
        l = i;
        r = i + 1;

        while (l >= 0 && r < n && s[l] == s[r]) {
            if (r - l + 1 > maxLen) {
                start = l;
                maxLen = r - l + 1;
            }
            l--;
            r++;
        }
    }

    return s.substr(start, maxLen);
}

int main() {
    string s;
    cin >> s;

    cout << longestPalindrome(s);

    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1) extra space
