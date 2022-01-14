// Problem Link
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
    int minSubArrayLen(int target, vector<int> &nums)
    {       
        int res = INT_MAX;
        int l = 0, sum = 0;
        
        for(int r=0; r<nums.size(); r++)
        {
            sum = sum + nums[r];            
            
            while(sum>=target)
            {   
                res = min(res, r-l+1);
                sum=sum-nums[l++];
            }
        }
        
        return res==INT_MAX?0:res;
           
    }
};