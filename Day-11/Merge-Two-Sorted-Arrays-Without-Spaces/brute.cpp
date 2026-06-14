#include <iostream>
#include <algorithm>
using namespace std;

/*
Merge Two Sorted Arrays with extra space
 arr1 after : {0, 1, 2, 3} and arr2 : {5, 6, 7, 8, 9}

question will be asked till arrays not mentioning "with extra space"

*/

int main(){

    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};

    int n = arr1.size();
    int m = arr2.size();

    vector<int> arr3(n + m);

    int left = 0;
    int right = 0;
    int index = 0;

    while(left < n && right < m){
        if(arr1[left] <= arr2[right]){
            arr3[index] = arr1[left];
            left++;
            index++;
        }
        else{
            arr3[index] = arr2[right];
            right++;
            index++;
        }
    }

    while(left < n){
        arr3[index++] = arr1[left++];
    }

    while(right < m){
        arr3[index++] = arr2[right++];
    }

    for(int i = 0; i < n; i++){
        arr1[i] = arr3[i];
    }

    for(int i = 0; i < m; i++){
        arr2[i] = arr3[n + i];
    }


    for(int i = 0; i < n; i++){
        cout << arr1[i] << " ";
    }

    cout << endl;

    for(int i = 0; i < m; i++){
        cout << arr2[i] << " ";
    }

    return 0;
}

// Time Complexity: O(n) 
// Space Complexity: O(1)

