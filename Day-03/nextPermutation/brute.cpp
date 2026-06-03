#include <iostream>
#include <vector>
using namespace std;

// brute-force

// Next Permutation

// Given an array of integers, find the next permutation of the given array. The replacement must be in place and use only constant extra memory.
// permuted array should be in order of next greater permutation of numbers. If such arrangement is not possible, it must be rearranged as the lowest possible order (i.e., sorted in ascending order).
// if last permutation is given then return first one

// eg: 1 2 3 -> 1 3 2 is the next permutation then 2 1 3 then 1

int main(){

    vector <int> array = {1, 2, 5, 4, 3};
    int n = array.size();
    int position = -1;

    // break point where the order is not increasing

    for(int i = n - 2; i >= 0; i--){
        if(array[i] < array[i + 1]){
            position = i;
            break;
        }
    }

    if (position == -1) { // then the whole array will be in decreasing order
        sort(array.begin(), array.end());
    }
    else {
        // Step 2: Find smallest element greater than pivot

        for (int i = n - 1; i > position; i--) {
            if (array[i] > array[position]) {
                swap(array[i], array[position]); // last se start kr rhe to isliye ek bar m hi break point bale element se just greater mil jayega
                // 2, 1, 5, 4, 3, 0, 0 ab isme break point h 1 p to peeche se sb increasing order m h
                // to 1 se just bda hi milega hmesa, na ki 4 ya 5 and 0 to chota h to ignore
                break;
            }
        }

        // Step 3: Sort the remaining elements

        for (int i = position + 1; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (array[i] > array[j]) {
                    swap(array[i], array[j]);
                }
            }
        }
    }

    // print it
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }

    cout << endl;
    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)


// other approach

/*
1. generate all permutation in sorted order by recursion
2. linear search
3. return next one

but very high complexity
*/
