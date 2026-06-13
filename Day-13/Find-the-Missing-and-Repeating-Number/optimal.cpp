#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// "Optimal 2 = XOR approach (not studied yet)".

// Find the missing and repeating number
// given an array of n size
// arr = {4, 3, 6, 2, 1, 1} so here 5 is missing and 1 is repeating so return both

// optimal using mathematical operation

int main(){

    vector <int> arr = {4, 3, 6, 2, 1, 1};
    long long n = arr.size();

    // s - Sn2 = x - y, where x = repeating, y = missing we are doing s2 - sn2 isliye x = repeating h
    // s2 - S2n

    long long Sn = (n * (n + 1)) / 2;
    long long Sn2 = (n * (n + 1) * (2 * n + 1)) / 6;
    long long s = 0;
    long long s2 = 0;

    for(int i = 0; i < n; i++){
        s += arr[i];
        s2 += arr[i] * arr[i];
    }

    long long num1 = s - Sn; // x - y
    long long num2 = s2 - Sn2;
    num2 = num2 / num1; // x + y as x^2 - y^2 (this is diff2) = (x+y)(x-y)

    long long x = (num1 + num2) / 2;
    long long y = x - num1;

    cout << x << " " << y; // just return the num in int back

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
