// https://practice.geeksforgeeks.org/problems/brackets-in-matrix-chain-multiplication1024/1/#
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
    vector<int> arr;
    int brakets[501][501];
    int dp[501][501];
    string res = "";

public:
    string matrixChainOrder(int p[], int n)
    {

        for (int i = 0; i < n; i++)
            arr.push_back(p[i]);

        char c = 'A';

        memset(dp, -1, sizeof(dp));

        mcm(0, n);
        storeString(1, n - 1, c);
        return res;
    }

    void storeString(int i, int j, char &c)
    {
        if (i == j)
        {
            res.push_back(c++);
            return;
        }

        res.push_back('(');

        storeString(i, brakets[i][j], c);
        storeString(brakets[i][j] + 1, j, c);

        res.push_back(')');
        return;
    }

    int mcm(int i, int j)
    {
        if (i == j)
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        dp[i][j] = INT_MAX;

        for (int k = i; k < j; k++)
        {
            int s = mcm(i, k) + mcm(k + 1, j) + arr[i - 1] * arr[j] * arr[k];

            if (dp[i][j] >= s)
            {
                brakets[i][j] = k;
                dp[i][j] = s;
            }
        }

        return dp[i][j];
    }
};