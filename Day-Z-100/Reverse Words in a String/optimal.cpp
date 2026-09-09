#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Reverse Words in a String

string reverseWords(string s) {
    reverse(s.begin(), s.end());

    int n = s.size();
    int i = 0, j = 0;

    while (i < n) {
        // Skip spaces
        while (i < n && s[i] == ' ')
            i++;

        if (i >= n)
            break;

        // Find end of word
        j = i;
        while (j < n && s[j] != ' ')
            j++;

        // Reverse current word
        reverse(s.begin() + i, s.begin() + j);

        i = j;
    }

    // Remove extra spaces
    string ans;
    for (int k = 0; k < n; k++) {
        if (s[k] != ' ' || (k > 0 && s[k - 1] != ' '))
            ans += s[k];
    }

    if (!ans.empty() && ans.back() == ' ')
        ans.pop_back();

    return ans;
}

int main() {
    string s = "the sky is blue";

    cout << reverseWords(s);

    return 0;
}

/*
Time Complexity: O(n)
Space Complexity: O(n)
*/
