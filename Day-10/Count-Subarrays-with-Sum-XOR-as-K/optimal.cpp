#include <iostream>
#include <vector>
#include <map>
using namespace std;

// Count Subarrays with Sum XOR as K
// approach: x = XR ^ k, where XR = current total Xor and x is the elements of array

int main(){

    vector<int> arr = {4, 2, 2, 6, 4};
    int n = arr.size();

    int k;
    cout << "Enter the value of K: ";
    cin >> k;

    map <int, int> mpp;
    mpp[0] = 1; // imp 🔥 xor 0 has count 1

    int xr = 0;
    int count = 0;

    for(int i = 0; i < n; i++){
        xr ^= arr[i];
        int x = xr ^ k; // currently xr and k h hmare pass to agr x mil gya to sb ok h because k = xr ^ x
        count += mpp[x]; // ye map k count ko increase NAHI kr ra 🔥
        mpp[xr]++; // hr new xr ke count ko store kra rhe kitni bar appear hua
    }

    cout << count << endl;


    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(n)
