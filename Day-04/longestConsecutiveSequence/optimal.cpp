#include <iostream>
#include <unordered_set>
using namespace std;

int main(){

    vector <int> arr = {100, 102, 100, 101, 101, 4, 3, 2, 3, 2, 1, 1, 1, 2};
    int n = arr.size();
    unordered_set <int> st;
    int longest = 1;

    for(int i = 0; i < n; i++){
        st.insert(arr[i]);
    }

    for(auto it : st){
        if(st.find(it - 1) == st.end()){ // if previous element ni mila to
            int count = 1;
            int current = it;
            while(st.find(current + 1) != st.end()){ // current + 1 mila to
                current += 1;
                count += 1;
            }
            longest = max(longest, count);
        }
    }
    cout << longest << endl;
    return 0;
}

we are checking preious one only to avoid count next one's eg: for 2 we see 1 not 3 4 5 and then get to know 1 exists

// Time Complexity: 🔥 O(3n) not O(n^2 + n) kyuki jese n = 7 ho gya st k liye to 7 times iterate hoga then uske andar 1 bar m 3 + 4 this is for auto it loops and for previous loop O(n)
// Space Complexity: O(n)
