#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Koko Eating Bananas

/*
Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.(means if or pile[i] takes 3.5hrs we will take it 4 then move to next pile)

Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

Return the minimum integer k such that she can eat all the bananas within h hours.
*/

/*
approach: min hrs = 1 and max = max(piles)
*/

bool canFinish(vector<int>& arr, int mid, int h){

    long long totalHrs = 0;

    for(int i = 0; i < arr.size(); i++){
        totalHrs += ceil((double(arr[i]) / mid)); // or (arr[i] + k - 1) / k;

        if(totalHrs > h){
            return false;
        }
    }

    // if(totalHrs <= h){ // h is given hrs to usse km time lgega to possibly hm or km time m kr skte
    //     return true;
    // }
    // else{
    //     return false;
    // }

    // or

    return totalHrs <= h;
}

int main(){

    vector<int> piles = {3, 6, 7, 11};
    
    int h;
    cout << "enter h: ";
    cin >> h;

    int start = 1;
    int end = *max_element(piles.begin(), piles.end());
    int ans = -1;

    while(start <= end){
        int mid = start + ((end - start) / 2);

        if(canFinish(piles, n, mid, h)){
            ans = mid;
            end = mid - 1;   // try smaller speed
        }
        else{
            start = mid + 1;    // need faster speed
        }
    }

    cout << ans << endl;

    return 0;
}

// Time Complexity: O(n * log(maxPile)) // means max value from the pile
// Space Complexity: O(1)
