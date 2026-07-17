#include <iostream>
using namespace std;

// Maximum Value at a Given Index in a Bounded Array

long long getSum(long long peak, int len)
{
    if (peak > len)
    {
        long long first = peak - len;
        long long last = peak - 1;

        return (first + last) * len / 2;
    }

    long long sum = (peak - 1) * peak / 2;
    sum += (len - (peak - 1));

    return sum;
}

int maxValue(int n, int index, int maxSum)
{
    int start = 1;
    int end = maxSum;
    int ans = 1;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;

        long long leftSum = getSum(mid, index);
        long long rightSum = getSum(mid, n - index - 1);

        long long totalSum = leftSum + rightSum + mid;

        if (totalSum <= maxSum)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return ans;
}

int main()
{
    int n = 4;
    int index = 2;
    int maxSum = 6;

    cout << maxValue(n, index, maxSum);

    return 0;
}

// Time Complexity: O(log(maxSum))
// Space Complexity: O(1)
