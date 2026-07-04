#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> transpose(vector<vector<int>>& matrix) {

    int row = matrix.size();
    int col = matrix[0].size();

    vector<vector<int>> ans(col, vector<int>(row));

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
            ans[j][i] = matrix[i][j];
        }
    }

    return ans;
}

int main() {

    vector<vector<int>> matrix = {
        {1,2,3},
        {4,5,6}
    };

    vector<vector<int>> ans = transpose(matrix);

    for(int i = 0; i < ans.size(); i++) {
        for(int j = 0; j < ans[0].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

// Time Complexity: O(row * col)
// Space Complexity: O(row * col)
