#include <iostream>
#include <vector>
using namespace std;

// Merge Sorted Array

int main() {

    vector<int> arr1 = {1, 3, 5, 7};
    vector<int> arr2 = {0, 2, 6, 8, 9};

    int n = arr1.size();
    int m = arr2.size();

    int len = n + m;

    int gap = (len / 2) + (len % 2);

    while(gap > 0) {

        int left = 0;
        int right = left + gap;

        while(right < len) {

            // both pointers in arr1
            if(left < n && right < n) {

                if(arr1[left] > arr1[right]) {
                    swap(arr1[left], arr1[right]);
                }
            }

            // left in arr1, right in arr2
            else if(left < n && right >= n) {

                if(arr1[left] > arr2[right - n]) {
                    swap(arr1[left], arr2[right - n]);
                }
            }

            // both pointers in arr2
            else {

                if(arr2[left - n] > arr2[right - n]) {
                    swap(arr2[left - n], arr2[right - n]);
                }
            }

            left++;
            right++;
        }

        if(gap == 1) {
            break;
        }

        gap = (gap / 2) + (gap % 2);
    }

    for(int x : arr1) {
        cout << x << " ";
    }

    cout << endl;

    for(int x : arr2) {
        cout << x << " ";
    }

    return 0;
}

// Time Complexity: O((n + m)log(n + m)) 
// Space Complexity: O(1)
