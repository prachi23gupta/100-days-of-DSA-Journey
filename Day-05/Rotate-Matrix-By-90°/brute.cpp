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
    // int p = n - 1; ye bi likh skte h instead of n - 1 - i

    vector<vector<int>> rotated_matrix(n, vector<int>(m));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            rotated_matrix[j][n - 1 - i] = matrix[i][j];
        }  
    }

    for(auto r : rotated_matrix){
        for(auto ele : r){
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(n * m)
// Space Complexity: O(n * m)
