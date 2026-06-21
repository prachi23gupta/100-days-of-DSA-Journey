#include <iostream>
#include <vector>
using namespace std;

// Finding Sqrt of a number using Binary Search
// eg: given n = 30 return 5

int main(){

    int n;
    cout << "Enter n : ";
    cin >> n;

    int start = 0;
    int end = n;

    while(start <= end){
        int mid = start + ((end - start) / 2);
        long long square = 1LL * mid * mid;

        if(square == n){
            cout << mid << endl;
            return 0;
        }

        if(square < n){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }

    cout << end << endl;

    return 0;
}

// Time Complexity: O(logn)
// Space Complexity: O(1)
