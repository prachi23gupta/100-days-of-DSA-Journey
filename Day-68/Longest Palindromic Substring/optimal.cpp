#include <iostream>
#include <string>

using namespace std;

// Longest Palindromic Substring

// Given a string s, return the longest palindromic substring in s

// approach: instead of checking from the ends, we check every possible center.

void expandFromCenter(const string &s, int left, int right, int &start, int &maxLength){

    while(left >= 0 && right < s.length() && s[left] == s[right]){
        left--;
        right++;
    }

    int currentLength = right - left - 1;

    if(currentLength > maxLength){
        maxLength = currentLength;
        start = left + 1;
    }
}

string longestPalindrome(const string &s){

    if(s.empty()){
        return "";
    }

    int start = 0;
    int maxLength = 1;

    for(int i = 0; i < s.length(); i++){

        // Odd length palindrome
        expandFromCenter(s, i, i, start, maxLength);

        // Even length palindrome
        expandFromCenter(s, i, i + 1, start, maxLength);
    }

    return s.substr(start, maxLength);
}

int main(){

    string s;
    cout << "Enter a string: ";
    getline(cin, s);

    string longestPalindromicSubstring = longestPalindrome(s);

    cout << "Longest Palindromic Substring: " << longestPalindromicSubstring << endl;

    return 0;
}

// Time Complexity: O(n²)
// Space Complexity: O(1)
