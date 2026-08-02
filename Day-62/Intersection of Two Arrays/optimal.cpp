#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Intersection of Two Arrays

vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
{
    unordered_set<int> st(nums1.begin(), nums1.end());
    unordered_set<int> ans;

    for (int num : nums2)
    {
        if (st.find(num) != st.end())
        {
            ans.insert(num);
        }
    }

    return vector<int>(ans.begin(), ans.end());
}

int main()
{
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> result = intersection(nums1, nums2);

    cout << "Intersection: ";
    for (int num : result)
    {
        cout << num << " ";
    }

    cout << endl;

    return 0;
}

/*
Time Complexity: O(n + m)
Space Complexity: O(n)
*/
