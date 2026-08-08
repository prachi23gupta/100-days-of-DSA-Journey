#include <iostream>
using namespace std;

// Detect Capital

bool detectCapitalUse(string word) {
    int n = word.length();

    // Case 1: all uppercase
    if (isupper(word[0])) {
        bool allUpper = true;

        for (int i = 1; i < n; i++) {
            if (islower(word[i])) {
                allUpper = false;
                break;
            }
        }

        if (allUpper) {
            return true;
        }

        // Case 2: first uppercase, rest lowercase
        for (int i = 1; i < n; i++) {
            if (isupper(word[i])) {
                return false;
            }
        }

        return true;
    }

    // Case 3: all lowercase
    for (int i = 1; i < n; i++) {
        if (isupper(word[i])) {
            return false;
        }
    }

    return true;
}

int main() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    cout << boolalpha << detectCapitalUse(word);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
