#include <iostream>
#include <string>
using namespace std;

// Is Subsequence

int main() {

    string s = "abc";
    string t = "ahbgdc";

    int i = 0;
    int j = 0;

    while (i < s.length() && j < t.length()) {

        if (s[i] == t[j]) {
            i++;
        }

        j++;
    }

    if (i == s.length())
        cout << "true";
    else
        cout << "false";

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
