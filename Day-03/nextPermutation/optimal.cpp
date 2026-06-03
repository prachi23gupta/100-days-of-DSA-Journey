#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// optimal

int main(){

    vector <int> array = {1, 2, 5, 4, 3}; 
    int n = array.size();
    int pivot = -1;

    // break point where the order is not increasing

    for(int i = n - 2; i >= 0; i--){
        if(array[i] < array[i + 1]){
            pivot = i;
            break;
        }
    }

    if (pivot == -1) { // then the whole array will be in decreasing order
        sort(array.begin(), array.end());
    }
    else {
        // Step 2: Find smallest element greater than pivot

        for (int i = n - 1; i > pivot; i--) {
            if (array[i] > array[pivot]) {
                swap(array[i], array[pivot]);
                break;
            }
        }

        // Step 3: reverse the remaining array after pivot index

        int left = pivot + 1;
        int right = n - 1;

        while(left < right){
            swap(array[left], array[right]);
            left++;
            right--;
        }
    }

    // print it
    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }

    cout << endl;
    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
