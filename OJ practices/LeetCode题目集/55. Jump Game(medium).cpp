/**
 * @file 55. Jump Game(medium).cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 判断能否跳到目的地
 * @version 1.0.0
 * @date 2024-03-20
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 贪心算法
 * 看起点到能跳最远处的点之间的点谁能再跳到最远，作为下一次跳的起点
 * 复杂度：时间 O(n) 空间 O(1)
 * 
 * https://leetcode.cn/problems/jump-game/description/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int n = nums.size();
        int maxReach = nums[0];
        int s = 0;
        while (maxReach < n - 1)
        {
            int nextS = s;
            int nextMaxReach = maxReach;
            for (int i = s + 1; i <= maxReach; ++i)
            {
                if (nextMaxReach < nums[i] + i)
                {
                    nextMaxReach = nums[i] + i;
                    nextS = i;
                }
            }
            if (s == nextS)
            {
                return false;
            }
            
            s = nextS;
            maxReach = nextMaxReach;
        }
        return true;
    }
};