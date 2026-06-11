#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Merge Two Sorted Arrays without extra space
// approach: 1st array ka last element compare with 2nd array ka first el

int main(){

    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};

    int n = arr1.size();
    int m = arr2.size();

    int left = n - 1;
    int right = 0;

    while(left >= 0 && right < m){
        if(arr1[left] > arr2[right]){
            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else{
            break; // as sorted h to koi or bi condition puri ni kr payega
        }
    }

    sort(arr1.begin(), arr1.end());
    sort(arr2.begin(), arr2.end());

    for(int i = 0; i < n; i++){
        cout << arr1[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < m; i++){
        cout << arr2[i] << " ";
    }

    return 0;
}

// Time Complexity: O(min(n, m) + O(n log n) + O(m log m)); 
// Space Complexity: O(1)
