#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> // for using *max_element
#include <numeric> // for using accumulate
using namespace std;

// Capacity to ship packages within D days

// approach: if eg 25 possible h to 25 k bad bale sari possible capacity hongi but hmko min lena h to left side jayege range is 1 to max(arr) otherwise right side jayege

bool minCapacity(vector<int>& arr, int cap, int d){

    int daysUsed = 1; // first day is already being used
    int load = 0;

    for(int i = 0; i < arr.size(); i++){
        if(load + arr[i] > cap){

            daysUsed++;
            load = arr[i];

            if(daysUsed > d){ // for less TC
                return false;
            }
        }
        else{
            load += arr[i];
        }
    }
    return daysUsed <= d;
}

int main(){

    vector<int> weights = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // not sorted
    
    int days;
    cout << "enter total days: ";
    cin >> days;

    int start = *max_element(weights.begin(), weights.end());
    int end = accumulate(weights.begin(), weights.end(), 0);
    int ans = -1;

    while(start <= end){
        int mid = start + ((end - start) / 2);

        if(minCapacity(weights, mid, days)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}

// Time Complexity: O(n * log(sum(weights) - max(weights)))
// Space Complexity: O(1)
