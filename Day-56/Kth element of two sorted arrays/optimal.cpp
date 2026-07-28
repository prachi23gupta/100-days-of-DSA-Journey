#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// Kth element of two sorted arrays

// means two sorted are given so what will be the Kth el ifff they were merged
// idea is same as median of two sorted array(previous ques) just here we dont break it into half but at k
// means agr total 10 el h to left side 4 and right side 6 to max of left side will be the answer

int kthElement(vector<int>& a, vector<int>& b, int k) {
    int n1 = a.size();
    int n2 = b.size();

    if (n1 > n2)
        return kthElement(b, a, k);

    int low = max(0, k - n2);
    int high = min(k, n1);

    while (low <= high) {
        int cut1 = (low + high) >> 1;
        int cut2 = k - cut1;

        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;

        if (cut1 > 0)
            l1 = a[cut1 - 1];
        if (cut2 > 0)
            l2 = b[cut2 - 1];

        if (cut1 < n1)
            r1 = a[cut1];
        if (cut2 < n2)
            r2 = b[cut2];

        if (l1 <= r2 && l2 <= r1)
            return max(l1, l2);
        else if (l1 > r2)
            high = cut1 - 1;
        else
            low = cut1 + 1;
    }

    return -1;
}

int main() {
    vector<int> a = {2, 3, 6, 7, 9};
    vector<int> b = {1, 4, 8, 10};

    int k = 5;

    cout << "The " << k << "th element is: " << kthElement(a, b, k);

    return 0;
}

// Time Complexity: O(log(min(n1, n2)))
// Space Complexity: O(1)
