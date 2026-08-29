#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// Maximum Product of Word Lengths

int maxProduct(vector<string>& words) {
    int n = words.size();
    vector<int> mask(n, 0);

    for (int i = 0; i < n; i++) {
        for (char c : words[i]) {
            mask[i] |= (1 << (c - 'a'));
        }
    }

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((mask[i] & mask[j]) == 0) {
                ans = max(ans,
                          (int)words[i].size() * (int)words[j].size());
            }
        }
    }

    return ans;
}

int main() {
    vector<string> words = {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};

    cout << maxProduct(words);

    return 0;
}

// Time Complexity: O(n^2 + total characters)
// Space Complexity: O(n)
