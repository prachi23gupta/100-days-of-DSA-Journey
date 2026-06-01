#include <iostream>
#include <vector>
using namespace std;

// Moore's voting algorithm

int main(){
    vector<int> v = {7, 7, 5, 7, 5, 1, 5, 7, 5, 5, 7, 7, 5, 5, 5, 5};

    int el;
    int count = 0;
    for(int i = 0; i < v.size(); i++){
        if(count == 0){
            el = v[i];
        }
        else if(v[i] == el){
            count++;
        }
        else{
            count--;
        }
    }
    int count1 = 0;
    for(int i = 0; i < v.size(); i++){
        if(v[i] == el){
            count1++;
        }
    }
    if(count1 > (v.size() / 2)){
        cout << "majority element is " << el << endl;
    }
    return 0;
}

// Time Complexity = O(N) and additional O(N) only if el don't exist
// Space Complexity = O(1)
