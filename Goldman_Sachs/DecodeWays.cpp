// https://practice.geeksforgeeks.org/problems/total-decoding-messages1235/1/#
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution
{
    unordered_map<int, int> dp;

public:
    int CountWays(string str)
    {
        int n = str.size();
        return solve(0, str, n);
    }

    int solve(int i, string &str, int &n)
    {
        if (i == n)
            return 1;

        if (i > n || str[i] == '0')
            return 0;

        int c = stoi(str.substr(i, 2));

        if (dp.find(i) != dp.end())
            return dp[i];

        dp[i] = solve(i + 1, str, n);

        if (c <= 26)
            dp[i] = (dp[i] + solve(i + 2, str, n)) % 1000000007;

        return dp[i];
    }
};