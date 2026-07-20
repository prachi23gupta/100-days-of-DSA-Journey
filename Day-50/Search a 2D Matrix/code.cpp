#include <iostream>
#include <vector>
using namespace std;

// Search a 2D Matrix

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

int main() {

    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    int target = 3;

    if (searchMatrix(matrix, target))
        cout << "True";
    else
        cout << "False";

    return 0;
}

// Time Complexity: O(m * log n)
// Space Complexity: O(1)
