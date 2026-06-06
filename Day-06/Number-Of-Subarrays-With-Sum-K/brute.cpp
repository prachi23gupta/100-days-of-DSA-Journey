#include <iostream>
#include <vector>
using namespace std;

// Number Of Subarrays With Sum K

// eg: [-3, 1, 1, 1, 4, 2, -3] if sum = k

int main() {

    vector<int> arr = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};

    int k;
    cout << "Enter the value of K: ";
    cin >> k;

    int n = arr.size();
    int count = 0;

    for(int i = 0; i < n; i++) {

        for(int j = i; j < n; j++) {

            int sum = 0;

            for(int l = i; l <= j; l++) {
                sum += arr[l];
            }

            if(sum == k) {
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}
// Time Complexity: O(n^3)
// Space Complexity: O(1)
