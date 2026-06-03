#include <iostream>
#include <vector>
using namespace std;

// brute-force

// leaders in array = every element on right side of that particulr element should be smaller
// multiple leaders can be there

int main(){

    vector <int> array = {10, 22, 12, 3, 0, 6};
    int n = array.size();

    for(int i = 0; i < n; i++){
        int j;
        for(j = i + 1; j < n; j++){
            if(array[j] > array[i]){
                break;
            }
        }
        if(j == n){
            cout << array[i] << " ";
        }
    }

    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
