#include <iostream>
#include <vector>
using namespace std;

// Book allocation problem

/*
Given an array 'arr' of integer numbers, 'arr[i]' represents the number of pages in the 'i-th' book.

There are 'm' number of students, and the task is to allocate all the books to the students.

Allocate books in such a way that:

1. Each student gets at least one book.
2. Each book should be allocated to only one student.
3. Book allocation should be in a contiguous manner.

You have to allocate the book to 'm' students such that the maximum number of pages assigned to a student is minimum.
If the allocation of books is not possible, return -1.
*/

/*
means 

| Student 1    | Student 2    | Pages  |
| ------------ | ------------ | ------ |
| [10]         | [20, 30, 40] | 10, 90 |
| [10, 20]     | [30, 40]     | 30, 70 |
| [10, 20, 30] | [40]         | 60, 40 |

max(10, 90) = 90
max(30, 70) = 70
max(60, 40) = 60 ✅

*/

// approach:
// mid should be pages that we try to allocate if possible then more than that is also possible

bool isPossible(vector<int> &arr, int mid, int n, int m){
    int cnt = 1; // first student ko first book m hi rakh do
    int sum = 0;

    for(int i = 0; i < n; i++){
        if(sum + arr[i] > mid){
            cnt++;
            sum = arr[i];
        } else {
            sum += arr[i];
        }

        if(cnt > m){
            return false;
        }
    }

    return true;
}

int main(){

    vector<int> arr = {10, 20, 30, 40};
    int n = arr.size();

    int m;
    cout << "Enter the number of students: ";
    cin >> m;

    if(m > n){
        cout << -1 << endl;
        return 0;
    }

    int start = *max_element(arr.begin(), arr.end());
    int end = 0;
    int ans = -1;

    for(int x : arr){
        end += x;
    }

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(isPossible(arr, mid, n, m)){
            ans = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }

    }

    cout << ans << endl;

    return 0;
}

// Time Complexity: O(n * log(sum - max_element))
// Space Complexity: O(1)
