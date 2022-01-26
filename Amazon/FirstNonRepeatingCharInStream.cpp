// https://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream1216/1#
#include <algorithm>
#include <unordered_map>
#include <map>
#include <vector>
#include <string>
#include <set>
#include <stack>
#include <queue>

using namespace std;

class Solution
{
public:
    string FirstNonRepeating(string A)
    {

        queue<char> q;
        string res = "";
        unordered_map<char, int> mp;

        int n = A.length();

        mp[A[0]]++, res += A[0], q.push(A[0]);

        for (int i = 1; i < n; i++)
        {
            mp[A[i]]++;

            // Last Unique Character if same as Current Character, means now its not unique anymore
            if (A[i] == q.front())
            {
                // Keep popping the queue unless the front character in the queue is a unique character
                while (!q.empty() && mp[q.front()] >= 2)
                    q.pop();
            }
            else if (mp[A[i]] == 1)
                q.push(A[i]);

            res += (q.empty() ? '#' : q.front());
        }

        return res;
    }
};