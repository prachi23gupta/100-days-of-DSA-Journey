#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// Determine if Two Strings Are Close

bool closeStrings(string word1, string word2) {
    if (word1.length() != word2.length()) {
        return false;
    }

    vector<int> freq1(26, 0);
    vector<int> freq2(26, 0);

    for (char ch : word1) {
        freq1[ch - 'a']++;
    }

    for (char ch : word2) {
        freq2[ch - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if ((freq1[i] == 0) != (freq2[i] == 0)) {
            return false;
        }
    }

    sort(freq1.begin(), freq1.end());
    sort(freq2.begin(), freq2.end());

    return freq1 == freq2;
}

int main() {
    string word1, word2;

    cin >> word1 >> word2;

    cout << (closeStrings(word1, word2) ? "true" : "false");

    return 0;
}

// Time Complexity: O(n + m + 26 log 26)
// Space Complexity: O(26)
