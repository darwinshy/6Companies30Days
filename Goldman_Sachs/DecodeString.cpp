
// https://leetcode.com/problems/minimum-size-subarray-sum/
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <stack>

using namespace std;

string decodedString(string s)
{
    int i = 0;
    return decode(s, i);
}

string decode(string &s, int &i)
{
    string characters = "", count = "";

    for (; i < s.size(); i++)
    {
        char c = s[i];

        if (isdigit(c))
            count.push_back(c);
        else if (isalpha(c))
            characters.push_back(c);
        else if (c == '[')
        {
            string sub = decode(s, ++i);

            if (count.length() != 0)
            {
                int p = stoi(count);
                while (p--)
                    characters += sub;
                count.clear();
            }
        }
        else if (c == ']')
            return characters;
    }

    return characters;
}
