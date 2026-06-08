#include <iostream>
#include <vector>
using namespace std;

// Majority Element II - occurance > n/3 times
// similar to Moore's algo
// approach: any array can have at max 2 elements with above condition

int main(){

    vector <int> arr = {1, 1, 1, 3, 3, 2, 2, 2};    int n = arr.size();

    int count1 = 0;
    int count2 = 0;
    int el1;
    int el2;

    for(int i = 0; i < n; i++){
        if(count1 == 0 && arr[i] != el2){ // both variable should not have the same element
            count1 = 1;
            el1 = arr[i];
        }
        else if(count2 == 0 && arr[i] != el1){
            count2 = 1;
            el2 = arr[i];
        }
        else if(el1 == arr[i]){
            count1++;
        }
        else if(el2 == arr[i]){
            count2++;
        }
        else{
            count1--;
            count2--;
        }
    }

    // manual check for el1
    int chk1 = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == el1){
            chk1++;
        }
    }
    if(chk1 > (arr.size() / 3)){
        cout << "majority element is " << el1 << endl;
    }

    // manual check for el2

    int chk2 = 0;
    for(int i = 0; i < arr.size(); i++){
        if(arr[i] == el2){
            chk2++;
        }
    }
    if(chk2 > (arr.size() / 3)){
        cout << "majority element is " << el2 << endl;
    }

    return 0;
}

// Time Complexity: O(n)
// Space Complexity: O(1)
