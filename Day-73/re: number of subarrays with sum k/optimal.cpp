#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Number Of Subarrays With Sum K

// eg: [-3, 1, 1, 1, 4, 2, -3] if sum = k

// prefix sum

int main(){

    vector <int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    int n = arr.size();

    int k;
    cout << "Enter the value of K: ";
    cin >> k;

    unordered_map <int, int> mpp;
    mpp[0] = 1; // imp 🔥

    int preSum = 0;
    int count = 0;

    for(int i = 0; i < n; i++){
        preSum += arr[i];
        int removeSum = preSum - k;
        count += mpp[removeSum];
        mpp[preSum] += 1;
    }

    cout << count << endl;

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)


/*
hashmap: (key, value) = (preSum, count)
*/
