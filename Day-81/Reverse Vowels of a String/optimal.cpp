#include <iostream>
#include <string>
using namespace std;

// Reverse Vowels of a String

int isVowel(char c) {
    c = tolower(c);
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(){

    string s = "leetcode";

    int start = 0;
    int end = s.length() - 1;

    while(start < end){

        // Move start pointer to the next vowel
        while(start < end && !isVowel(s[start])){
            start++;
        }

        // Move end pointer to the previous vowel
        while(start < end && !isVowel(s[end])){
            end--;
        }

        // Swap the vowels
        swap(s[start], s[end]);

        start++;
        end--;
    }

    cout << "answer is: " << s << endl;

    return 0;
}
