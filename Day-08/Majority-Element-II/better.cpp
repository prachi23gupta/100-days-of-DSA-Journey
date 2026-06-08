#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Majority Element II - occurance > n/3 times
// using hashmap

int main(){

    vector <int> arr = {1, 1, 1, 3, 3, 2, 2, 2};
    int n = arr.size();

    unordered_map<int, int> mp;

    for(int i = 0; i < n; i++){
        mp[arr[i]]++; // setting arr[i] as key in hashmap
    }

    for(auto it : mp){
        if(it.second > n/3){
            cout << it.first << " ";
        }
    }

    return 0;
}

// Time Complexity: O(n) + O(n) = O(n)
// Space Complexity: O(n)
