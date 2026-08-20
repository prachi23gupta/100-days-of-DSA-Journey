#include <iostream>
#include <vector>
using namespace std;

// Rotate Matrix/Image by 90 degree

// 1  2  3  4          13  9  5  1
// 5  6  7  8          14 10  6  2
// 9  10 11 12         15 11  7  3
// 13 14 15 16         16 12  8  4

int main(){

    vector<vector<int>> matrix = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int n = matrix.size();
    int m = matrix[0].size();
    
    // Transpose

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // reverse each row

    for(int i = 0; i < n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
    }


    for(auto r : matrix){
        for(auto ele : r){
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(n^2)
// Space Complexity: O(1)


// alternate of reversing each row we can swap columns too

    // for(int j = 0; j < n / 2; j++){
    //     for(int i = 0; i < n; i++){
    //         swap(matrix[i][j], matrix[i][n - 1 - j]);
    //     }
    // }
