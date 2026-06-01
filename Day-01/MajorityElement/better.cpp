#include <iostream>
#include <unordered_map>
using namespace std;

// Majority element - any element in arr that appears more than N / 2 times

int main(){
    unordered_map<int, int> mp;
    int arr[] = {1, 3, 5, 2, 2, 1, 2, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i = 0; i < n; i++){
        mp[arr[i]]++;
    }

    for(auto it : mp){
        if(it.second > n/2){
            cout << "Majority element: " << it.first;
            return 0;
        }
    }

    cout << "No majority element";

    return 0;
}

// Time Complexity = O(N) or O(N) in worst case
// Space Complexity = O(N)
