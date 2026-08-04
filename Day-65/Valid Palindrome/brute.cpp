#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Valid Palindrome

// Given a string s, return true if it is a palindrome, otherwise return false.
// A palindrome is a string that reads the same forward and backward. It is also case-insensitive and ignores all non-alphanumeric characters.
// Note: Alphanumeric characters consist of letters (A-Z, a-z) and numbers (0-9).


// Input: s = "Was it a car or a cat I saw?"

// Output: true


bool isPalindrome(string s){

    int start = 0;

    for(char &c : s)
        c = tolower(c);

    // now remove all non-alphanumeric characters from the string

    string temp = "";

    for(char c : s){
        if(isalnum(c)){ // either alphabet or digit
            temp += c;
        }
    }

    s = temp;

    int end = s.length() - 1;

    while(start < end){
        if(s[start] != s[end]){
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
    } else {
        cout << "false" << endl;
    }

    return 0;
}

// Time Complexity: O(n)
// Space Complexxity: O(1)
