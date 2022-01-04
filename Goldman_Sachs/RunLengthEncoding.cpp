// https://practice.geeksforgeeks.org/problems/run-length-encoding/1/#
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>

using namespace std;

using namespace std;

string encode(string src)
{
    string res = "";
    int n = src.size();

    int c = 1;

    for (int i = 0; i < n; i++)
    {
        int ac = 1;
        res += src[i];

        while (src[i] == src[i + 1] && i + 1 < n)
        {
            ac++;
            i++;
        }

        res += to_string(ac);
    }

    return res;
}