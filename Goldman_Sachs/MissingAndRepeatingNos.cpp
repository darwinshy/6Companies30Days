// https://practice.geeksforgeeks.org/problems/find-missing-and-repeating2512/1/#
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
    int *findTwoElement(int *arr, int n)
    {

        int i = -1, j = -1;

        for (int p = 0; p < n; p++)
        {
            if (arr[abs(arr[p]) - 1] < 0)
                i = abs(arr[p]);
            else
                arr[abs(arr[p]) - 1] = -arr[abs(arr[p]) - 1];
        }

        for (int s = 0; s < n; s++)
        {
            if (arr[s] > 0)
            {
                j = s + 1;
                break;
            }
        }

        int *res = new int[2];
        res[0] = i;
        res[1] = j;

        return res;
    }
};