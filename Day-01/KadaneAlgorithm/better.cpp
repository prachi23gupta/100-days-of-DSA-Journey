#include <iostream>
#include <vector>
using namespace std;

// Maximum Subarray sum - Kadane's algorithm

int main(){
    vector<int> v = {-2, -3, 4, -1, -2, 1, 5, -3};

    int maxSum = INT_MIN;

    for(int i = 0; i < v.size(); i++){
        int sum = 0;
        for(int j = i; j < v.size(); j++){
            sum += v[j];
            maxSum = max(maxSum, sum);
        }
    }
    cout << "Maximum Subarray Sum = " << maxSum << endl;

    return 0;
}
// Time Complexity = O(N**2)
// Space Complexity = O(1)
