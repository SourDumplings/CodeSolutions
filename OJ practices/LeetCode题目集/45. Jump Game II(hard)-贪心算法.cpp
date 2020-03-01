/*
 * @Author: SourDumplings
 * @Date: 2020-03-01 21:09:49
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/jump-game-ii/
 * 
 * 该算法就是每次选择能跳的范围内，让下一次跳的最远的作为下一跳的落点
 */

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int res = 0;
        int maxJumpPos = 0;
        int lastMaxJumpPos = 0;
        int l = nums.size();
        for (int i = 0; i < l - 1; i++)
        {
            maxJumpPos = max(maxJumpPos, nums[i] + i);
            if (i == lastMaxJumpPos)
            {
                lastMaxJumpPos = maxJumpPos;
                ++res;
            }
        }
        return res;
    }
};