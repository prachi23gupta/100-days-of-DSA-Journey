#include <iostream>
#include <vector>
using namespace std;

// Search in 2D matrix

/*
return True or False if target found

approach: check in a row if target is > oth index el and < last el
*/

bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows = matrix.size();
        int cols = matrix[0].size();

        for (int i = 0; i < rows; i++) {

            if (target >= matrix[i][0] && target <= matrix[i][cols - 1]) {

                int start = 0;
                int end = cols - 1;

                while (start <= end) {

                    int mid = start + (end - start) / 2;

                    if (matrix[i][mid] == target)
                        return true;

                    else if (matrix[i][mid] < target)
                        start = mid + 1;

                    else
                        end = mid - 1;
                }
            }
        }

        return false;
    }

int main(){

    vector<vector<int>> arr = {{3, 4, 7, 9}, {12, 13, 16, 18}, {20, 21, 23, 29}};

    int target;

    cout << "Enter Target from the array: ";
    cin >> target;

    if(searchMatrix(arr, target)){
        cout << "True" << endl;
    }
    else{
        cout << "False" << endl;
    }

    return 0;
}
