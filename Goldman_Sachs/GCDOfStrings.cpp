// https://leetcode.com/problems/greatest-common-divisor-of-strings/
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {

        int m = str1.size();
        int n = str2.size();

        int gc = gcd(m, n);

        if (str1 + str2 == str2 + str1)
            return str1.substr(0, gc);
        else
            return "";
    }

    int gcd(int a, int b)
    {
        if (b == 0)
            return a;
        return gcd(b, a % b);
    }
};