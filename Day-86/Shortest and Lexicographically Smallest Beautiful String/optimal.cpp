#include <iostream>
#include <string>
using namespace std;

// Shortest and Lexicographically Smallest Beautiful String

string shortestBeautifulSubstring(string s, int k) {
    int left = 0, ones = 0;
    string ans = "";

    for (int right = 0; right < s.length(); right++) {
        if (s[right] == '1')
            ones++;

        while (ones > k) {
            if (s[left] == '1')
                ones--;
            left++;
        }

        if (ones == k) {
            while (s[left] == '0')
                left++;

            string curr = s.substr(left, right - left + 1);

            if (ans.empty() ||
                curr.length() < ans.length() ||
                (curr.length() == ans.length() && curr < ans)) {
                ans = curr;
            }
        }
    }

    return ans;
}

int main() {
    string s;
    int k;

    cin >> s >> k;

    cout << shortestBeautifulSubstring(s, k);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
