// easy but not straight forward binary search question

#include <iostream>
using namespace std;

// Search in a 2D matrix - II

// 🔥 the concwpt of BS is applied here, not directly but in elimination it is used

/*
in given matrix the el in row is sorted and in a col also up to down sorted

return {row, col} number
*/

// approach: see from every corner than you realise at {1, m} ek side increse and ek side decrease to decide kr skste h baki sare corners pr either decrease or increase
// to basically -------- ese increase ho ra h ulta 7 bale raste m
                //     |
                //     |
                //     | 

int main(){

    int row = 0;
    int col = m -1

    while(row < n && col >= 0){
        if(mat[row][col] == target){
            return (row, col);  
        }
        else if(mat[row][col] > target){
            col--;
        }
        else{
            row++;
        }
    }
    return{-1, -1}

    return 0;
}

// Time Complexity: O(n + m)
// Space Complexity: O(1)
