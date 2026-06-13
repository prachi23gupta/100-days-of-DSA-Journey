#include <iostream>
#include <vector>
using namespace std;

// Find the missing and repeating number
// given an array of n size
// arr = {4, 3, 6, 2, 1, 1} so here 5 is missing and 1 is repeating so return both

int main(){

    vector <int> arr = {4, 3, 6, 2, 1, 1};
    int n = arr.size();
    int missing = -1;


    for(int i = 0; i < n; i++){
        
        for(int j = i + 1; j < n; j++){
            if(arr[i] == arr[j]){
                cout << "duplicate number is: " << arr[i] << endl;
            }
        }

    }

    for(int num = 1; num <= n; num++){

        bool found = false;

        for(int j = 0; j < n; j++){
            if(arr[j] == num){
                found = true;
                break;
            }
        }

        if(!found){
            missing = num;
            break;
        }
    }

    cout << "Missing number is: " << missing << endl;

    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
