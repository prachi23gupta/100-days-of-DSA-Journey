// before seeing chatgppt dry run from image just run this code bo jyada better samjhayega exact calling kb kiski kiske bad hogi

/*
array is given you need to sort it by merge sort
do part m divide kro by finding mid and again broken part ko or broke kro jb tk single block na aa jaye ye sb merge sort kr ra h
just trying to explain kya hota h
then sort it and merge
*/

/*
Method 1: using recursion:
    merge 2 sorted arrays after dividing main array in 2 parts

Method 2: use indexes
    start, end index of array
*/

#include <iostream>
using namespace std;

void merge(int *arr, int s, int e){
    cout << "merge(" << s << "," << e << ")" << endl;
    int mid = (s+e)/2;

    int len1 = mid - s + 1; // +1 as we need to include mid also
    int len2 = e - mid;

    int *first = new int[len1]; // new hmne isliye banaya as we need to store the elements of left part in this array
    int *second = new int[len2];

    // now we need to copy in above arrays

    int mainArrayIndex = s;
    for(int i = 0; i < len1; i++){
        first[i] = arr[mainArrayIndex++];
    }

    mainArrayIndex = mid + 1;
    for(int i = 0; i < len2; i++){
        second[i] = arr[mainArrayIndex++];
    }

    // merge

    int index1 = 0;
    int index2 = 0;

    mainArrayIndex = s;

    // here is the main sorting happening

    while(index1 < len1 && index2 < len2){
        if(first[index1] < second[index2]){
            arr[mainArrayIndex] = first[index1]; // we used ++ as we will first copy it then increment. because it is post incement not pre increment

            // arr[index++] is same as arr[index] then index++

            index1++;
            mainArrayIndex++;
        }
        else{
            arr[mainArrayIndex++] = second[index2++];
        }
    }

    // we will come out of above loop when one of the array is completely traversed and other may have some elements left so we need to copy those elements in main array
    
    while(index1 < len1){
        arr[mainArrayIndex++] = first[index1++];
    }

    while(index2 < len2){
        arr[mainArrayIndex++] = second[index2++];
    }

}

void mergeSort(int *arr, int s, int e){
    cout << "mergeSort(" << s << "," << e << ")" << endl;

    // base case
    if(s >= e){
        return;
    }

    int mid = (s + e) / 2;

    // left part sort krna h
    mergeSort(arr, s, mid);

    // right part sort krna h
    mergeSort(arr, mid+1, e);

    // merge sorted halves
    merge(arr, s, e);

}

int main(){

    int arr[5] = {2, 5, 1, 6, 9};
    int n = 5;

    mergeSort(arr, 0, n-1);

    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }

    return 0;
}

/*
Most students think merging happens while going down. It doesn't.
You go down recursively, then merge while coming back up.
*/
