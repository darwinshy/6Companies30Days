// https://practice.geeksforgeeks.org/problems/find-the-position-of-m-th-item1723/1/#
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
    int findPosition(int N, int M, int K)
    {

        if (N - K + 1 >= M)
            return (M + K - 1);

        M = M - (N - K + 1);

        return M % N == 0 ? N : M % N;
    }
};