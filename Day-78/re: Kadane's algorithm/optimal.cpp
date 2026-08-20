#include <iostream>
#include <climits>
#include <vector>
using namespace std;

// Maximum Subarray sum - Kadane's algorithm

int main(){
    vector<int> v = {-2, -3, 4, -1, -2, 1, 5, -3};

    int currentSum = 0;
    int maxSum = INT_MIN;

    for(int i = 0; i < v.size(); i++){

        // this is just if ask to print that subarray

        // if(currentSum == 0){
        //     start = i;
        // }

        currentSum += v[i];
        
        maxSum = max(maxSum, currentSum);

        // this is just if ask to print that subarray

        // if(currentSum > maxSum){
        //     maxSum = currentSum;
        //     ansStart = start, ansEnd = i;
        // }
        
        if(currentSum < 0){
            currentSum = 0;
        }
    }
    cout << "Maximum Subarray Sum = " << maxSum << endl;

    return 0;
}
// Time Complexity = O(N)
// Space Complexity = O(1)
