/*
 * @Author: SourDumplings
 * @Date: 2020-12-29 21:39:50
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/house-robber-ii/
 * 
 * 采用动态规划法，
 * 要么从 0 号房间开始，要么从 1 号房间开始，一次走两格抢到尾
 * 状态转移方程：
 * dp[n]=max(dp[n - 1], dp[n − 2] + nums[n])
 * 因为不能相邻，所以不用考虑循环问题
 * 
 * 参考：https://leetcode-cn.com/problems/house-robber-ii/solution/213-da-jia-jie-she-iidong-tai-gui-hua-jie-gou-hua-/
 */

class Solution
{
private:
    int do_rob(vector<int> &nums, int b, int e)
    {
        int pre = 0, cur = 0, temp;
        for (int i = b; i < e; ++i)
        {
            temp = cur;
            cur = max(pre + nums[i], cur);
            pre = temp;
        }
        return cur;
    }

public:
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        if (n == 1)
        {
            return nums[0];
        }
        return max(do_rob(nums, 0, n - 1), do_rob(nums, 1, n));
    }
};