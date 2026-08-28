#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Lexicographically Smallest Palindromic Permutation Greater Than Target

string lexPalindromicPermutation(string s, string target) {
    int n = s.size();
    vector<int> freq(26, 0);

    for (char c : s)
        freq[c - 'a']++;

    int odd = 0, mid = -1;

    for (int i = 0; i < 26; i++) {
        if (freq[i] & 1) {
            odd++;
            mid = i;
        }
    }

    if (odd > 1)
        return "";

    for (int i = 0; i < 26; i++)
        freq[i] /= 2;

    int half = n / 2;
    string left(half, 'a');

    auto build = [&]() {
        string ans = left;

        if (mid != -1)
            ans += char('a' + mid);

        for (int i = half - 1; i >= 0; i--)
            ans += left[i];

        return ans;
    };

    int pos = 0;

    while (pos < half) {
        int c = target[pos] - 'a';

        if (freq[c] == 0)
            break;

        left[pos] = target[pos];
        freq[c]--;
        pos++;
    }

    if (pos == half) {
        string ans = build();

        if (ans > target)
            return ans;
    }

    while (true) {
        if (pos < half) {
            int start = target[pos] - 'a' + 1;

            for (int c = start; c < 26; c++) {
                if (freq[c] == 0)
                    continue;

                left[pos] = char('a' + c);
                freq[c]--;

                int idx = pos + 1;

                for (int j = 0; j < 26; j++) {
                    while (freq[j] > 0) {
                        left[idx++] = char('a' + j);
                        freq[j]--;
                    }
                }

                return build();
            }
        }

        if (pos == 0)
            return "";

        pos--;
        freq[target[pos] - 'a']++;
    }
}

int main() {
    string s, target;
    cin >> s >> target;

    cout << lexPalindromicPermutation(s, target) << endl;

    return 0;
}

// Time Complexity: O(26 * n)
// Space Complexity: O(n)
