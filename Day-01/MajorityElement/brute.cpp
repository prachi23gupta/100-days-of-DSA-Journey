// pick each element go through the array to increase count then compare if it's more than n/2
// then repeat for all elements

#include <iostream>
using namespace std;

int main(){
    int arr[] = {1, 3, 5, 2, 2, 1, 2, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int num;

    for(int i = 0; i < n; i++){
        int count = 0;

        for(int j = 0; j < n; j++){
            if(arr[j] == arr[i]){
                count++;
            }
        }
        if(count > n / 2){
            num = arr[i];
            break;
        }
    }
    cout << num << endl;

    return 0;
}

// Time Complexity = O(N**2)
// Space Complexity = O(1)
