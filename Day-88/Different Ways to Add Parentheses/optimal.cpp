#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// Different Ways to Add Parentheses

vector<int> solve(string s, unordered_map<string, vector<int>>& memo) {
    if (memo.count(s))
        return memo[s];

    vector<int> ans;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '*') {
            vector<int> left = solve(s.substr(0, i), memo);
            vector<int> right = solve(s.substr(i + 1), memo);

            for (int a : left) {
                for (int b : right) {
                    if (s[i] == '+')
                        ans.push_back(a + b);
                    else if (s[i] == '-')
                        ans.push_back(a - b);
                    else
                        ans.push_back(a * b);
                }
            }
        }
    }

    if (ans.empty())
        ans.push_back(stoi(s));

    return memo[s] = ans;
}

vector<int> diffWaysToCompute(string expression) {
    unordered_map<string, vector<int>> memo;
    return solve(expression, memo);
}

int main() {
    string expression = "2*3-4*5";

    vector<int> ans = diffWaysToCompute(expression);

    for (int x : ans)
        cout << x << " ";

    return 0;
}

// Time Complexity: O(3^n) in the worst case
// Space Complexity: O(3^n)
