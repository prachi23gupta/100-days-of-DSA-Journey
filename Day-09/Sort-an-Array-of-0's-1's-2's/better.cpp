#include <iostream>
using namespace std;

// sort an array of 0's, 1's, 2's

int main(){
    int arr[] = {1, 0, 2, 1, 1, 2, 2, 0, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int count0 = 0;
    int count1 = 0;
    int count2 = 0;

    for(int i = 0; i < n; i++){
        if(arr[i] == 0){
            count0 += 1;
        }
        else if(arr[i] == 1){
            count1 += 1;
        }
        else{
            count2 += 1;
        }
    }

    cout << count0 << endl;
    cout << count1 << endl;
    cout << count2 << endl;

    for(int i = 0; i < count0; i++){
        arr[i] = 0;
    }
    for(int i = count0; i < (count0 + count1); i++){
        arr[i] = 1;
    }
    for(int i = (count0 + count1); i < n; i++){
        arr[i] = 2;
    }

    for(int i = 0; i < n; i++){
        cout << arr[i] << endl;
    }

    return 0;
}


// Time Complexity = O(n)
// Space Complexity = O(1)
