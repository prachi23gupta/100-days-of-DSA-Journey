#include <iostream>
#include <vector>
using namespace std;

// Peak element-II

/*

A peak element in a 2D grid is an element that is strictly greater than all of its adjacent neighbors to the left, right, top, and bottom.

Given a 0-indexed m x n matrix mat where no two adjacent cells are equal, find any peak element mat[i][j] and return the length 2 array [i,j].

You may assume that the entire matrix is surrounded by an outer perimeter with the value -1 in each cell.

*/

/*
- Pick the middle column.
- Find the maximum element in that column.
- Compare it only with its left and right neighbors.
- Move left or right using binary search based on that comparison.

*/

bool isPossible(vector<vector<int>> &arr, int row, int col){

    int num_col = arr[0].size() - 1;

    int left;
    int right;

    if(col == 0){
        left = -1;
    }
    else{
        left = arr[row][col - 1];
    }

    if(col == num_col){
        right = -1;
    }
    else{
        right = arr[row][col + 1];
    }

    if(arr[row][col] > left && arr[row][col] > right){
        return true;
    }

    return false;
}

int main(){

    vector<vector<int>> mat = {
        {4, 2, 5, 1, 4, 5},
        {2, 9, 3, 2, 3, 2},
        {1, 7, 6, 0, 1, 3},
        {3, 6, 2, 3, 7, 2}
    };

    int n = mat.size();
    int m = mat[0].size();

    int start = 0;
    int end = m - 1;

    while(start <= end){

        int mid = (start + end) / 2; // to find middle column

        int maxRow = 0; // har naye mid = liye maxRow 0 krna pdega

        for(int i = 1; i < n; i++){

            if(mat[i][mid] > mat[maxRow][mid]){
                maxRow = i; // to find max element in that column
            }
        }

        if(isPossible(mat, maxRow, mid)){
            cout << "Peak Element Index: " << maxRow << ", " << mid << endl;
            break;
        }

        if(mid != m - 1 && mat[maxRow][mid] < mat[maxRow][mid + 1]){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    return 0;
}

// Time Complexity: O(n * log m)
// Space Complexity: O(1)
