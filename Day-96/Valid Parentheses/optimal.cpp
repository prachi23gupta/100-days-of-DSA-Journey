#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Valid Parentheses

bool isValid(string s) {
    stack<char> st;

    for (char ch : s) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        }
        else {
            if (st.empty())
                return false;

            if (ch == ')' && st.top() != '(')
                return false;
            if (ch == '}' && st.top() != '{')
                return false;
            if (ch == ']' && st.top() != '[')
                return false;

            st.pop();
        }
    }

    return st.empty();
}

int main() {
    string s;
    cin >> s;

    if (isValid(s))
        cout << "true";
    else
        cout << "false";

    return 0;
}
