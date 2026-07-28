#include <iostream>
using namespace std;

// Find the row with maximum 1's

/*
if found multiple rows return the row with smaller index
row number starts from 0
*/

int row(vector<vector<int>>& arr, int maxCnt, int i){

    int n = arr[i].size();
    int start = 0;
    int end = n - 1;
    int cnt = 0;

    while(start <= end){
        int mid  = start + (end - start) / 2;

        if(arr[i][mid] == 1){
            cnt = n - mid; // because n shows number of elements not last el index
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return cnt;
}

int main(){

    vector<vector<int>> arr = {{0, 0, 1, 1, 1}, {0, 0, 0, 0, 0}, {0, 1, 1, 1, 1}, {0, 0, 0, 0, 0}, {0, 1, 1, 1, 1}};

    int maxcnt = 0;
    int ans = -1;

    for(int i = 0; i < arr.size(); i++){
        if(row(arr, maxcnt, i) > maxcnt){
            maxcnt = row(arr, maxcnt, i);
            ans = i;
        }
    }

    cout << ans << endl;

    return 0;
}
