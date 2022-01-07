// https://practice.geeksforgeeks.org/problems/number-following-a-pattern3126/1#
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
    string printMinNumberForPattern(string S)
    {

        stack<int> st;
        string res = "";
        int i = 1;

        for (char c : S)
        {
            if (c == 'D')
                st.push(i++); // DDDDDD will result in 123456 -> 654321
            else
            {
                st.push(i++);

                // Save the increasing order as it is.
                while (!st.empty())
                {
                    char x = '0' + st.top();
                    res.push_back(x);
                    st.pop();
                }
            }
        }

        st.push(i++);

        while (!st.empty())
        {
            char x = '0' + st.top();
            res.push_back(x);
            st.pop();
        }

        return res;
    }
};