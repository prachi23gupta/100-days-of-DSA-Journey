#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Interval List Intersections

int main() {
    vector<vector<int>> firstList = {{0,2}, {5,10}, {13,23}, {24,25}};
    vector<vector<int>> secondList = {{1,5}, {8,12}, {15,24}, {25,26}};

    vector<vector<int>> ans;

    int i = 0;
    int j = 0;

    while (i < firstList.size() && j < secondList.size()) {

        int start = max(firstList[i][0], secondList[j][0]);
        int end = min(firstList[i][1], secondList[j][1]);

        // Intersection exists
        if (start <= end) {
            ans.push_back({start, end});
        }

        // Move the interval which ends first
        if (firstList[i][1] < secondList[j][1]) {
            i++;
        } else {
            j++;
        }
    }

    for (auto interval : ans) {
        cout << "[" << interval[0] << ", " << interval[1] << "] ";
    }

    return 0;
}

// Time Complexity: O(n + m)
// Space Complexity: O(k)
