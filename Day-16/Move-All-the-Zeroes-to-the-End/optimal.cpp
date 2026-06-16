#include <iostream>
using namespace std;

//Move all the zeroes to the end of the array

//OPTIMAL SOLUTION

int main(){

    int arr[] = {1, 0, 3, 0, 23, 0, 0, 2, 1, 8,  0};
    int n = sizeof(arr)/sizeof(arr[0]);

    int j = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            j = i;
            break;
        }
    }
    for(int i = j + 1; i < n; i++){
        if(arr[i] != 0){
            swap(arr[i], arr[j]);
            j++;
        }
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Time complexity = O(N) + O(N-N) = O(N)
// Space complexity = O(1)
