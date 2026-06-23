#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Minimum days to make M bouquets

/*
You are given an integer array bloomDay, an integer m and an integer k.

You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.

The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.

Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.

*/

/*

Approach:
Binary Search on days.

If it is possible to make m bouquets on day X,
then it will also be possible on every day > X.

This forms a monotonic pattern:
false false false true true true

Hence Binary Search can be applied on the answer space.

*/

/*
Mistake:
Converted the original bloomDay array into 0s and 1s.
This modified the input array permanently.

Since Binary Search calls this function multiple times,
the actual bloom day values were lost after the first call,
causing incorrect results in later iterations.

int bloomed(vector<int>& arr, int mid){

    for(int i = 0; i < arr.size(); i++){
        if(arr[i] <= mid){
            arr[i] = 1;
        }
        else{
            arr[i] = 0;
        }
    }

    return false;
}
*/

bool canPair(const vector<int>& arr, int mid, int m, int k){

    int cntM = 0;
    int cntToK = 0;
    for(int i = 0; i < arr.size(); i++){

        if(arr[i] <= mid){
            cntToK++;

            if(cntToK == k){
                cntM++;
                cntToK = 0;
            }
        }
        else{
            cntToK = 0;
        }

        if(cntM >= m){
            return true;
        }
    }

    return false;
}


int main(){

    vector<int> bloomDay = {7, 7, 7, 7, 13, 11, 12, 7};
    int n = bloomDay.size();

    int m;
    cout << "enter m : ";
    cin >> m;

    int k;
    cout << "enter k : ";
    cin >> k;

    int start = *min_element(bloomDay.begin(), bloomDay.end());
    int end = *max_element(bloomDay.begin(), bloomDay.end());
    int ans = -1;

    if((long long)m * k > n){
        cout << -1;
        return 0;
    }

    while(start <= end){
        int mid = start +((end - start) / 2);

        if(canPair(bloomDay, mid, m, k)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    cout << ans;

    return 0;
}

// Time Complexity: O(n * log(maxBloomDay - minBloomDay))
// Space Complexity: O(1)
