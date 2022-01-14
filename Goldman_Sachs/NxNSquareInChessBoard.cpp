// https://practice.geeksforgeeks.org/problems/squares-in-nn-chessboard1801/1
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
    long long squaresInChessBoard(long long N)
    {

        long long res = 0;

        for (int i = 1; i <= N; i++)
            res = res + pow(i, 2);

        return res;
    }
};
