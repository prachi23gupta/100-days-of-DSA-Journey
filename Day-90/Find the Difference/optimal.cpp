#include <iostream>
#include <string>
using namespace std;

// Find the Difference

char findTheDifference(string s, string t) {
    char ans = 0;

    for (char c : s)
        ans ^= c;

    for (char c : t)
        ans ^= c;

    return ans;
}

int main() {
    string s = "abcd";
    string t = "abcde";

    cout << findTheDifference(s, t);

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
