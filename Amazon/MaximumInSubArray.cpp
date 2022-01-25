
// https://practice.geeksforgeeks.org/problems/deee0e8cf9910e7219f663c18d6d640ea0b87f87/1/

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
    vector<int> max_of_subarrays(vector<int> arr, int n, int k)
    {

        vector<int> res;
        int j = 0;
        multiset<int> ms;

        if (n == 1)
        {
            res.push_back(arr[0]);
            return res;
        }

        while (j < k)
        {
            ms.insert(arr[j]);
            j++;
        }

        res.push_back(*ms.rbegin());

        while (j < n)
        {
            ms.erase(ms.find(arr[j - k]));
            ms.insert(arr[j]);
            res.push_back(*ms.rbegin());
            j++;
        }

        return res;
    }
};