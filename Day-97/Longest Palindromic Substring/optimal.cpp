#include <iostream>
#include <string>
using namespace std;

// Longest Palindromic Substring

string longestPalindrome(string s) {
    int n = s.length();
    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {

        // Odd length palindrome
        int left = i, right = i;

        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
        }

        // Even length palindrome
        left = i;
        right = i + 1;

        while (left >= 0 && right < n && s[left] == s[right]) {
            if (right - left + 1 > maxLen) {
                start = left;
                maxLen = right - left + 1;
            }
            left--;
            right++;
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
// Space Complexity: O(1)
