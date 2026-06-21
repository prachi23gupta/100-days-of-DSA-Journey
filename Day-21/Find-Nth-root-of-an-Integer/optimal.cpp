#include <iostream>
using namespace std;

// Find Nth root of an Integer M

// N = 3 for M = 27 return (27)^(1/3) means cube root here = 3
// n = 4 and m = 69 then (69)^(1/4) = -1 because 69 doesn't have perfect root of 4
// another description Find x such that x^N = M

/*
approch: m**1/n == x so x**n == m
use square not root 🔥
*/

long long power(int mid, int N, int M) {

    long long ans = 1;

    for(int i = 1; i <= N; i++) {
        ans *= mid; // if n = 4 doing x*x*x*x then if we get exact root return 1 else if its too big then mid ki value km honi chayiye thi to hm nthrooth func m end = mid - 1 krege

        if(ans > M) {
            return 2; // mid^N > M
        }
    }

    if(ans == M) {
        return 1; // found
    }

    return 0; // mid^N < M
}

int NthRoot(int N, int M) {

    int start = 1;
    int end = M;

    while(start <= end) {

        int mid = start + (end - start) / 2;

        long long check = power(mid, N, M);

        if(check == 1) {
            return mid;
        }
        else if(check == 0) { // na hi ans bda h or na hi eqal to right side jana h
            start = mid + 1;
        }
        else {
            end = mid - 1; // yha answer bda ho gya M se to right jane pr or bda hoga isliye left
        }
    }

    return -1;
}

int main() {

    int N = 3;
    int M = 27;

    cout << NthRoot(N, M);

    return 0;
}

// Time Complexity: O(logn)
// Space Complexity: O(1)
