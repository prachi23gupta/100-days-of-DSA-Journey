#include <iostream>
#include <string>
using namespace std;

// Reverse Words in a String

string reverseWords(string s) {
    int n = s.length();
    int i = n - 1;

    string ans;

    while (i >= 0) {

        // Skip spaces
        while (i >= 0 && s[i] == ' ')
            i--;

        if (i < 0)
            break;

        int j = i;

        // Find beginning of word
        while (j >= 0 && s[j] != ' ')
            j--;

        if (!ans.empty())
            ans += ' ';

        ans += s.substr(j + 1, i - j);

        i = j - 1;
    }

    return ans;
}

int main() {
    string s;
    getline(cin, s);

    cout << reverseWords(s);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
