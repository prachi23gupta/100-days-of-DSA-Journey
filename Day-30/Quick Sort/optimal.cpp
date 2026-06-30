/* Quick sort */

#include <iostream>
using namespace std;

int partition(int *arr, int s, int e){
    int pivot = arr[s]; // we are taking first element as pivot

    int count = 0; // this will keep track of the last index of the smaller element

    for(int i = s+1; i <= e; i++){
        if(arr[i] <= pivot){
            count++; // increment index of smaller element
        }
    }

    // pivotIndex is pivot index
    int pivotIndex = s + count; // s is not gonna be 0 always that's why s is added

    // place the pivot in its correct position
    swap(arr[pivotIndex], arr[s]);

    // now put elements according to if > or < than pivot
    int i = s, j = e;

    while(i < pivotIndex && j > pivotIndex){
        while(arr[i] <= pivot){
            i++;
        }

        while(arr[j] > pivot){
            j--;
        }

        if(i < pivotIndex && j > pivotIndex){
            swap(arr[i++], arr[j--]);
        }
    }

    
    return pivotIndex; // return the index of the pivot
}

void quickSort(int *arr, int s, int e){

    // base case
    if(s >= e){
        return;
    }

    // partition
    int p = partition(arr, s, e);

    // recursive call on left part
    quickSort(arr, s, p - 1);

    // recursive call on right part
    quickSort(arr, p + 1, e);

}

int main(){

    int arr[] = {5, 2, 9, 1, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);

    // call quick sort function here
    quickSort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

/*
partition hr element k liye chlega until base case
*/

/*
Time complexity: O(n log n) in average and best case, O(n^2) in worst case (when the smallest or largest element is always chosen as pivot)
Space complexity: O(log n) on average and best case, O(n) in worst case
*/
