#include <iostream>
#include <vector>
using namespace std;

// Count Inversions in an Array
// return the count of the pairs having left element greater than right element without mixing the given array
// eg: from below array (5, 4) is ok but (4, 2) is not because we placed 4 on left of 2

int main(){

    vector <int> arr = {5, 3, 2, 4, 1};
    int n = arr.size();
    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(arr[i] > arr[j]){
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1);
