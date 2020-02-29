import java.util.Arrays;

/*
 * @Author: SourDumplings
 * @Date: 2020-02-29 19:39:59
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/jump-game-ii/
 */

class Solution
{
    public int jump(int[] nums)
    {
        int l = nums.length;
        int[] dp = new int[l];
        final int max = 999999;
        Arrays.fill(dp, max);
        dp[l - 1] = 0;
        for (int i = l - 2; 0 <= i; --i)
        {
            int maxJump = nums[i];
            for (int jump = maxJump; 0 < jump; --jump)
            {
                int reach = i + jump;

                if (l - 1 <= reach)
                {
                    dp[i] = 1;
                    break;
                }
                else if (dp[reach] + 1 < dp[i])
                {
                    dp[i] = dp[reach] + 1;
                }
            }
        }
        return dp[0];
    }
}