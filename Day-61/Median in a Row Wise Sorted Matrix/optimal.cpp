// tough one

#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

// Median in a Row Wise Sorted Matrix
// here we have odd n0. of rows and cols only

/*
here we need to take all matrix element and then find median not just in a row only
*/

/*
approach: jo bi median. hoga jaroori ri uske ek side small hi ho ya large hi ho sb kyuki equal bi ho skta h
ab jese total abhi 15 el h mat m to 7 idhr 7 udhr median k but but [no. of el <= median] > 7 honge median jo bi hoga us pr

ab isme  1 to 16 likh liye number and uske liye likha ki kitne isse <= h us particular position pr

so basically find out the first occurance where [no. of el <= median] > 7

find out ki kitne req se bde h not for every el but for only mid we call it blackbox and in that also we can use upperbound on every row then add for all

*/

int upperBound(vector<int>& arr, int x, int n){

    int start = 0;
    int end = n - 1;

    int ans = n;

    while (start <= end) {

        int mid = start + (end - start) / 2;

        if(arr[mid] > x){
            ans = mid; // we are keeping the answer but not taking a break as much smaller idx can be found
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return ans;

}

int count(vector<vector<int>>& mat, int n, int m, int x){

    int cnt = 0;
    for(int i = 0; i < n; i++){
        cnt += upperBound(mat[i], x, m);
    }

    return cnt;

}

int main(){

    vector<vector<int>> arr = {{1, 5, 7, 9, 11}, {2, 3, 4, 5, 10}, {9, 10, 12, 14, 16}};

    int n = arr.size();
    int m = arr[0].size();

    int start = arr[0][0];
    int end = arr[0][m - 1];

    int req = n * m / 2;

    for(int i = 0; i < n; i++){
        start = min(start, arr[i][0]);
        end = max(end, arr[i][m - 1]);
    }

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(count(arr, n, m, mid) <= req){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    cout << start << endl;

    return 0;
}
