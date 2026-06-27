#include <iostream>
using namespace std;

//Left Rotate Array by k places

//OPTIMAL SOLUTION

//preview
//reverse(a, a+d) => O(d)
//reverse(a+d, a+n) => O(n-d)
//reverse(a, a+n) => O(n)

void leftRotate(int arr[], int n, int d){
    d = d % n;
    reverse(arr, arr+d);
    reverse(arr+d, arr+n);
    reverse(arr, arr+n);
}

int main() {

    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int d = 5;

    leftRotate(arr, n, d);

    // Print rotated array
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Time complexity = O(d) + O(n-d) + O(n) = O(2n)
// Space complexity = O(1)🔥


//for reverse function if not defined in any language

// void Reverse(int arr[], int start, int end){

//     while (start <= end){

//         int temp = arr [start];
//         arr [startl = arr[end];
//         arr[end] = temp;
//         start++; end--;
//     }
// }
