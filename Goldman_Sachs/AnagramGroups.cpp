// https://practice.geeksforgeeks.org/problems/print-anagrams-together/1/
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<string>> Anagrams(vector<string> &string_list)
    {
        map<string, vector<string>> mp;
        vector<vector<string>> res;

        for (auto s : string_list)
        {
            string temp = s;
            sort(temp.begin(), temp.end());
            mp[temp].push_back(s);
        }

        for (auto s : mp)
            res.push_back(s.second);

        return res;
    }
};