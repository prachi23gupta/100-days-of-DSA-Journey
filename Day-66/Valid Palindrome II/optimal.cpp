#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Valid Palindrome II

/*
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

Example 1:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.

*/

// for eg like abca isme c htane or aba bchta h to b pr start and end ayega hi ni kyuki exceed ho jayegi condition

bool isPalindrome(const string &s, int start, int end){

    while(start < end){

        // Skip non-alphanumeric characters from the left
        while(start < end && !isalnum(s[start])){
            start++;
        }

        // Skip non-alphanumeric characters from the right
        while(start < end && !isalnum(s[end])){
            end--;
        }

        // Compare characters ignoring case
        if(tolower(s[start]) != tolower(s[end])){
            return false;
        }

        start++;
        end--;
    }

    return true;
}

bool isPalindrome(const string &s){

    int start = 0;
    int end = s.length() - 1;

    while(start < end){

        // Skip non-alphanumeric characters from the left
        while(start < end && !isalnum(s[start])){
            start++;
        }

        // Skip non-alphanumeric characters from the right
        while(start < end && !isalnum(s[end])){
            end--;
        }

        if(tolower(s[start]) != tolower(s[end])){

            // If characters don't match, we can either skip the left character or the right character
            return isPalindrome(s, start + 1, end) || isPalindrome(s, start, end - 1);
        }

        start++;
        end--;
    }

    return true;
}

int main(){

    const string s = "Was ait a car or a cat I saw?";

    if(isPalindrome(s)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
