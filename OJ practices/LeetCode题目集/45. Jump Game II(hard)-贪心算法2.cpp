/**
 * @file 45. Jump Game II(hard)-贪心算法2.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 算跳到终点的最少次数
 * @version 1.0.0
 * @date 2024-03-21
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 贪心算法，代码虽然丑但更好理解
 * https://leetcode.cn/problems/jump-game-ii/solutions/230241/tiao-yue-you-xi-ii-by-leetcode-solution/?envType=study-plan-v2&envId=top-interview-150
 * 
 * 复杂度：时间 O(n) 空间 O(1)
 */

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        
        int maxReach = nums[0];
        int s = 0;
        int res = 1;
        while (maxReach < n - 1)
        {
            int nextS = s;
            int nextMaxReach = maxReach;
            for (int i = s + 1; i <= maxReach; ++i)
            {
                if (nextMaxReach < i + nums[i])
                {
                    nextMaxReach = i + nums[i];
                    if (n - 1 <= nextMaxReach)
                    {
                        return res + 1;
                    }
                    nextS = i;
                }
            }
            s = nextS;
            maxReach = nextMaxReach;
            ++res;
        }
        return res;
    }
};