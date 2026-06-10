#include <iostream>
#include <vector>
using namespace std;

// Count Subarrays with Sum XOR as K

int main(){

    vector<int> arr = {4, 2, 2, 6, 4};
    int n = arr.size();

    int k;
    cout << "Enter the value of K: ";
    cin >> k;

    int count = 0;

    for(int i = 0; i < n; i++){
        
        for(int j = i; j < n; j++){

            if((arr[i] ^ arr[j]) == k){
                count++;
            }
            
        }
    }
    cout << count << endl;

    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
