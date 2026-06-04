#include <iostream>
#include <vector>
using namespace std;

// Set matrix zeroes

// in a matrix if somewhere is 0 then for whole row and column in which that particular 0 exist we need to put all of them 0
// eg: in a 3*3 matrix if a22 = 0 then put row 2 and column 2 values as 0

void markRow(vector<vector<int>>& matrix, int row){
    int m = matrix[0].size();

    for(int j = 0; j < m; j++){
        if(matrix[row][j] != 0){
            matrix[row][j] = -1;
        }
    }
}

void markCol(vector<vector<int>>& matrix, int col){
    int n = matrix.size();

    for(int i = 0; i < n; i++){
        if(matrix[i][col] != 0){
            matrix[i][col] = -1;
        }
    }
}

int main(){

    vector<vector<int>> matrix = {
        {1,1,1},
        {1,0,1},
        {1,1,1}
    };

    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(matrix[i][j] == 0){
                markRow(matrix, i);
                markCol(matrix, j);
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){

            if(matrix[i][j] == -1){
                matrix[i][j] = 0;
            }
        }
    }

    for(auto row : matrix){
        for(auto ele : row){
            cout << ele << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity = O(m*n*(m+n))
// Space Complexity = O(1)
