#include <iostream>
#include <vector>
using namespace std;

// Find ceil of an element

int ceilElement(vector<int>& arr, int x)
{
    int low = 0;
    int high = arr.size() - 1;
    int ans = -1;

    while(low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[mid] == x)
            return arr[mid];

        else if(arr[mid] > x)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
            low = mid + 1;
    }

    return ans;
}

int main()
{
    vector<int> arr = {2,3,5,9,14,16};
    int x = 10;

    cout << ceilElement(arr, x);

    return 0;
}

// Time Compleity: O(logn)
// Space Complexity: O(1)
