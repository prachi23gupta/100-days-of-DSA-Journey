#include <iostream>
#include <vector>
using namespace std;

// Number Of Subarrays With Sum K

// eg: [-3, 1, 1, 1, 4, 2, -3] if sum = k

int main(){

    vector <int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};

    int k;
    cout << "Enter the value of K: ";
    cin >> k;

    int n = arr.size();
    int count = 0;

    for(int i = 0; i < n; i++){
        int sum = 0;

        for(int j = i; j < n; j++){
            sum += arr[j];

            if(sum == k){
                count++;
            }
        }
    }

    cout << "No. of Subarrays with sum " << k << ": " << count << endl;

    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
