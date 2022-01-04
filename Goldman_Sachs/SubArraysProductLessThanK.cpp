// Problem Link
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>

using namespace std;
class Solution
{

    int res = 0;

public:
    int countSubArrayProductLessThanK(const vector<int> &a, int n, long long k)
    {

        int i = 0, j = 0;
        long long int p = 1;

        while (j < n)
        {
            p = p * a[j];

            while (p >= k && i < n)
            {
                p = p / a[i];
                i++;
            }

            res = res + (j - i + 1);
            j++;
        }

        return res;
    }
};