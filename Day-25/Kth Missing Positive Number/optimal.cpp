// See again

#include <iostream>
#include <vector>
using namespace std;

// Kth Missing Positive Number
// sorted array [2, 3, 4, 7, 11] kth = 5th then count from 1 to max el 1 is missing, 5, 6, 8, 9 and 10 so here 5th missing is 9

/*
brute-force:    for(i = 0; i < n; i++){
                    if(arr[i] <= k){
                        k++;
                    }
                    else{
                        break;
                    }
                }
approach is that for finding 5th missing we are taking 5 which can be least possible 5th ans then if any no. in array is smaller it will take 1 place
so we will move by 1 and if anyone is larger then break as array is sorted already
*/


/*
BS approach: 

Step 1: Missing count ka meaning samjho

Normal world mein agar koi number missing na ho:
Index:  0  1  2  3  4
Value:  1  2  3  4  5

Lekin actual array:
Index:  0  1  2  3  4
Value:  2  3  4  7  11

Index 4 par value 11 hai.
Agar kuch missing na hota to yahan 5 hona chahiye tha.
Difference:
11 - 5 = 6 Matlab index 4 tak total 6 numbers missing hain.
Isi liye:
missing = arr[i] - (i + 1)

Step 2: Binary Search kyun?
Hum k-th missing dhoondh rahe hain.

Example:
        missing counts:
        1 1 1 3 6
Agar k = 5 hai to hume pehli position chahiye jahan missing count 5 ya usse zyada ho.
1 1 1 3 6
        ^
Ye classic binary search on answer boundary hai.

Bilkul first occurrence jaisa:
F F F F T

Yahan:
missing < k  => F
missing >= k => T

Bas ye pattern yaad rakho.

Step 3: start + k ka logic

Loop ke baad:
start = first index where missing >= k

Maan lo:
start = 4, k = 5
To answer:
4 + 5 = 9
*/

int main(){

    vector<int> arr = {2, 3, 4, 7, 11};
    int n = arr.size();

    int k;
    cout << "enter k: ";
    cin >> k;

    int start = 0;
    int end = n - 1;;

    while(start <= end){
        int mid = start + ((end - start) / 2);

        int missing = arr[mid] - (mid + 1);

        if(missing < k){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    int ans = end + 1 + k; // or start + k

    cout << ans << endl;

    return 0;
}

// Time Complexity: O(logn)
// Space Complexity: O(1)
