// https://practice.geeksforgeeks.org/problems/maximum-profit4657/1#
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <stack>

using namespace std;

class Solution
{
public:
    int maxProfit(int K, int N, int A[])
    {

        int n = N;
        int k = K;

        if (n < 2)
            return 0;

        if (k > n / 2)
        {
            int ans = 0;
            for (int i = 1; i < n; ++i)
                ans += max(A[i] - A[i - 1], 0);
            return ans;
        }

        vector<int> buy(k + 1, INT_MIN), sell(k + 1, 0);

        for (int o = 0; o < n; o++)
        {
            for (int i = 1; i <= k; i++)
            {
                buy[i] = max(buy[i], sell[i - 1] - A[o]);
                sell[i] = max(sell[i], buy[i] + A[o]);
            }
        }

        return sell[k];
    }
};