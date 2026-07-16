#include <iostream>
#include <vector>
using namespace std;

// Painter's partition or split array-largest sum problem

/*
split the array into k subarrays such that the max subarray sum is minimum.
split should be continous and each subarray or painter should get at least one element.

jese length 10 h arr[i] ki or dusre ki h 20 to max 20 hi lgege dono sath m kam krege to esi sare possibility nikalo then take min
*/

bool isPossible(vector<int> &arr, int mid, int n, int m){
    int cnt = 1; // first painter ko first book m hi rakh do
    int sum = 0;

    for(int i = 0; i < n; i++){ // O(n)
        if(sum + arr[i] > mid){ // 🔥 overall sum should be <= mid
            cnt++;
            sum = arr[i]; // because agr p1 k pass mid se jyada sum aya to bo us block ko paint ni kr skta 🔥
        } else {
            sum += arr[i];
        }

        if(cnt > m){ // means painters jyada lgege ya samjho 2 painters assign hone k bad bi bacha hua h
            return false;
        }
    }

    return true;
}

int main(){

    vector<int> arr = {10, 20, 30, 40}; // array of boards and arr[i] = length of ith board
    int n = arr.size();

    int k;
    cout << "Enter the number of painters: ";
    cin >> k;

    if(k > n){
        cout << -1 << endl;
        return 0;
    }

    // O(n) for start
    int start = *max_element(arr.begin(), arr.end()); // agr esa ni kia jo jese 40 bala paint h bo koi ni paint kr payega to minimum yha se start krta hoga
    int end = 0;
    int ans = -1;

    for(int x: arr){ // O(n)
        end += x;
    }

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(isPossible(arr, mid, n, k)){
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

// Time Complexity: O(n) + O(n) + O(n) * O(logn) = O(nlogn)
// Space Complexity: O(1)
