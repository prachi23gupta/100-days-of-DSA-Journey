#include <iostream>
#include <vector>
using namespace std;

/*
First and Last Occurences of x
if not found return {-1, -1}
*/

int main(){

    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    int n = arr.size();

    int start = 0;
    int end = n - 1;

    int x;
    cout << "Enter the value of x: ";
    cin >> x;
    int first = -1;
    int last = -1;

    while (start <= end) {

        int mid = start + (end - start) / 2;

        if(arr[mid] == x){
            first = mid;
            end = mid - 1;
        }
        else if(arr[mid] > x){
            end = mid - 1;
        }
        else {
            start = mid + 1;
        }
    }

    // 🔥 if first occurence ni mila to mtlb x h hi ni so no need to go for last occurence
    if(first == -1){
        cout << first << " " << last << endl;
        return 0;
    }

    start = 0;
    end = n - 1;

     while (start <= end) {

        int mid = start + (end - start) / 2;

        if(arr[mid] == x){
            last = mid;
            start = mid + 1;
        }
        else if(arr[mid] < x){
            start = mid + 1;
        }
        else {
            end = mid - 1;
        }
    }

    cout << first << " " << last << endl;

    return 0;
}

// Time Complexity: O(log n) // base 2
// Space Complexity: O(1)

