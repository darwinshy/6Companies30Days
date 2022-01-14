// Problem Link
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
    bool canPair(vector<int> nums, int k)
    {
        map<int, int> mp;

        for (auto s : nums)
            mp[s % k]++;

        if (mp[0] % 2 != 0)
            return false;

        for (auto s : mp)
        {
            if (s.first != 0 && mp[k - s.first] != s.second)
                return false;
        }

        return true;
    }
};