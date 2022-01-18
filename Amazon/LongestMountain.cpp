// https://leetcode.com/problems/longest-mountain-in-array/
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
    int longestMountain(vector<int> &arr)
    {

        int n = arr.size();

        if (n < 3)
            return 0;

        int mx = 0;
        int i = 0;

        while (i < n)
        {

            int c1 = 0, c2 = 0;

            while (i + 1 < n && arr[i + 1] > arr[i])
            {
                i++;
                c1++;
            }
            while (i + 1 < n && arr[i + 1] < arr[i])
            {
                i++;
                c2++;
            }

            if (c1 != 0 && c2 != 0)
                mx = max(mx, c1 + c2 + 1);
            else if (c1 == 0 && c2 == 0)
                i++;
        }

        return mx;
    }
};