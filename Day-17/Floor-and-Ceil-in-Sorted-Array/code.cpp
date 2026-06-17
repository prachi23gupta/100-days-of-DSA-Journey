#include <iostream>
#include <vector>
using namespace std;

// floor and ceil in sorted array
// floor = largest no. <= x , ceil = smallest no. >= x
// for better understanding write two loops and notice common things then easy to combine

int main(){

    vector <int> arr = {10, 20, 25, 30, 40};
    int n = arr.size();

    int start = 0;
    int end = n - 1;
    int x = 21;
    int floor = -1;
    int ceil = -1;

    while(start <= end){
        int mid = start + (end - start) / 2;

        if(arr[mid] == x){
            floor = ceil = arr[mid];
            break;
        }
        else if(arr[mid] < x){
            floor = arr[mid];
            start = mid + 1;
        }
        else{
            ceil = arr[mid];
            end = mid - 1;
        }
    }   

    return 0;
}

// Time Complexity: O(log n)
// Space Complexity: O(1)
