// New pattern - min(max) or max(min) 

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Aggressive Cows

/*
Given an array of length ‘N’, where each element denotes the position of a stall. Now you have ‘N’ stalls and an integer ‘K’ which denotes
the number of cows that are aggressive. To prevent the cows from hurting each other, you need to assign the cows to the stalls, such that
the minimum distance between any two of them is as large as possible. Return the largest minimum distance.

here we find the possibility then jo bi distance honge k no. of cows k beech m uska min jese do k beech 4 ka distance h and another 2 m 5 ka to iska min lelo 4 ab ye ek possibility thi jisme 4 and 5 aa ra tha ese hi or hongi and then un min ka max lo

*/

/*
approach: sort it = kyuki uske baad min dist consecutives m hi mil jayega c1 and c3 m ni dhoondhna pdega

why to use BS? = kyuki agar x dist possible h to usse km bali bi possible hongi and vice-versa

*/

bool isPossible(vector<int> &arr, int mid, int n, int k){
    int cnt = 1; // first cow ko first stall m hi rakh do
    int lastPos = arr[0];

    for(int i = 1; i < n; i++){
        if(arr[i] - lastPos >= mid){
            cnt++;
            lastPos = arr[i];
        }

        if(cnt == k){
            return true;
        }
    }

    return false;
}

int main(){

    vector<int> arr = {0, 3, 4, 7, 9, 10};
    int n = arr.size();

    sort(arr.begin(), arr.end());

    int k = 3;

    int start = 0;
    int end = arr[n - 1];

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(isPossible(arr, mid, n, k)){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }

    }

    cout << end - 1 << endl;

    return 0;
}


// Time Complexity: O(nlogn + nlogm) = O(nlogn + nlogm) = O(nlogn)
// Space Complexity: O(1)
