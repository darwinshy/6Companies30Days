// https://practice.geeksforgeeks.org/problems/ugly-numbers2254/1/#
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
    unsigned long long getNthUglyNo(int n)
    {

        set<unsigned long long> s;
        n--;
        s.insert(1);

        while (n--)
        {
            auto bg = s.begin();
            unsigned long long i = *bg;

            s.erase(bg);
            s.insert(i * 2);
            s.insert(i * 3);
            s.insert(i * 5);
        }

        return *s.begin();
    }
};