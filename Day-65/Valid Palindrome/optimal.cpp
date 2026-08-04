#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Given a string s, return true if it is a palindrome, otherwise return false.
// A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.
// Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).

// Input: s = "Was it a car or a cat I saw?"

// Output: true

bool isPalindrome(string s){

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

        // Compare characters ignoring case
        if(tolower(s[start]) != tolower(s[end])){
            return false;
        }

        start++;
        end--;
    }

    return true;
}

int main(){

    string s = "Was it a car or a cat I saw?";

    if(isPalindrome(s)){
        cout << "true" << endl;
    }
    else{
        cout << "false" << endl;
    }

    return 0;
}
