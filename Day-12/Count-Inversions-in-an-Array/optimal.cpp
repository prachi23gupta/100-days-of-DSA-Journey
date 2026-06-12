#include <iostream>
#include <vector>
using namespace std;

// Count Inversions in an Array
// return the count of the pairs having left element greater than right element without mixing the given array
// eg: from below array (5, 4) is ok but (4, 2) is not because we placed 4 on left of 2

// by Merge sort

long long merge(vector<int>& arr, int s, int e) {

    int mid = (s + e) / 2;

    int len1 = mid - s + 1;
    int len2 = e - mid;

    vector<int> first(len1);
    vector<int> second(len2);

    int k = s;

    for (int i = 0; i < len1; i++) {
        first[i] = arr[k++];
    }

    k = mid + 1;

    for (int i = 0; i < len2; i++) {
        second[i] = arr[k++]; // or arr[k] then k++
    }

    int index1 = 0;
    int index2 = 0;
    k = s;

    long long count = 0;

    while (index1 < len1 && index2 < len2) {

        if (first[index1] <= second[index2]) {
            arr[k++] = first[index1++];
        }
        else {

            // inversion count
            count += (len1 - index1);

            arr[k++] = second[index2++];
        }
    }

    while (index1 < len1) {
        arr[k++] = first[index1++];
    }

    while (index2 < len2) {
        arr[k++] = second[index2++];
    }

    return count;
}

long long mergeSort(vector<int>& arr, int s, int e) {

    if (s >= e)
        return 0;

    int mid = (s + e) / 2;

    long long leftInv = mergeSort(arr, s, mid);
    long long rightInv = mergeSort(arr, mid + 1, e);

    long long crossInv = merge(arr, s, e);

    return leftInv + rightInv + crossInv;
}

int main() {

    vector<int> arr = {2, 5, 1, 6, 9};

    long long inversions = mergeSort(arr, 0, arr.size() - 1);

    cout << "Inversions = " << inversions << endl;

    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n);
