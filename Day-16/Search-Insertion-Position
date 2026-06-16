#include <iostream>
using namespace std;

// Search Insert Position

// Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

// eg: 1, 3, 5, 6 target is 2 then return 1

int main(){

    int target = 2;

    vector<int> arr = {1, 3, 5, 6};
    int n = arr.size();

    int start = 0;
    int end = n - 1;

    int x;
    cout << "Enter the value of x: ";
    cin >> x;
    int ans = n;

    while (start <= end) {

        int mid = start + (end - start) / 2;

        if(arr[mid] >= target){
            ans = mid;
            cout << ans;
            return 1;
        }
        else {
            start = mid + 1;
        }
    }

    return 0;
}
