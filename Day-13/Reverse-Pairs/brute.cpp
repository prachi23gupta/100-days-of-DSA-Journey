#include <iostream>
#include <vector>
using namespace std;

// Reverse Pairs
// condition: i < j && arr[i] > 2*arr[j]
// 

int main(){

    vector <int> arr = {40, 25, 19, 12, 9, 6, 2};
    int n = arr.size();
    int count = 0;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if( i < j && arr[i] > (2 * arr[j])){
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)
