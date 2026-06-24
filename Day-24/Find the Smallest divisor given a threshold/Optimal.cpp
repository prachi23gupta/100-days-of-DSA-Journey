#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Find the Smallest divisor given a threshold

/*
divisor can be in a range of 1 to max(arr)

for {1, 2, 5, 9} if we take 4 then 
1/4 = 1 (ceil value leni h)
2/4 = 1, 5/4 = 2, 9/4 = 3 total is 6 which is not <= threshold

if we take 5 then sahi answer h
*/

// approach: if eg 5 possible h to 5 k bad bale sare possible but hmko min lena h to left side jayege range is 1 to max(arr) otherwise right side jayege

bool possibleDivisor(vector<int>& arr, int mid, int x){

    int ans = 0;

    for(int i = 0; i < arr.size(); i++){
        ans += ceil((double(arr[i]) / mid));
    }

    if(ans <= x){
        return true;
    }
    return false;
}

int main(){

    vector<int> arr = {1, 5, 2, 9, 19, 25}; // not sorted
    
    int threshold;
    cout << "enter threshold: ";
    cin >> threshold;

    int start = 1;
    int end = *max_element(arr.begin(), arr.end());
    int ans = -1;

    while(start <= end){
        int mid = start + ((end - start) / 2);

        if(possibleDivisor(arr, mid, threshold)){
            ans = mid;
            end = mid - 1;   // try smaller divisor
        }
        else{
            start = mid + 1;    // need large divisor as this ans is exceeding the threshold
        }
    }

    cout << ans << endl;

    return 0;
}

// Time Complexity: O(n * log(max(arr)))
// Space Complexity: O(1)
