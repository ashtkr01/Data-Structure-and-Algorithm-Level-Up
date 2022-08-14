#include <bits/stdc++.h>
using namespace std;

long long minimumCost(vector<int> stones, int k)
{
    // Write your code here. Do not modify the function or the parameters. Use a helper function if needed.
    int n = stones.size();
    long long maximum = 0;
    vector<long long> vctr(n + 1, 0);
    for (int i = 2; i <= n; i++)
    {
        maximum = INT_MAX;
        for (int j = 1; j <= k; j++)
        {
            if (i - k >= 1)
            {
                maximum = min(maximum, vctr[i - k] + abs(stones[i - 1] - stones[i - 1 - k]));
            }
        }
        vctr[i] = maximum;
    }
    return vctr[n];
}