#include <iostream>
#include <vector>
using namespace std;

// Majority Element II - occurance > n/3 times

int main(){

    vector <int> arr = {1, 1, 1, 3, 3, 2, 2, 2};
    int n = arr.size();

    for(int i = 0; i < n; i++){
        int count = 1;
        for(int j = i + 1; j < n; j++){
            if(arr[j] == arr[i]){
                count++;
            }
        }
        if(count > n/3){
            cout << arr[i] << " ";
        }
    }

    cout << endl;

    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
