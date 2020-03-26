/*
 * @Author: SourDumplings
 * @Date: 2020-03-25 20:16:54
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/jump-game/
 * 
 * 使用贪心算法，每次都跳到能让下一跳最远的位置处，然后往回扫描
 */

class Solution
{
    public boolean canJump(int[] nums)
    {
        int l = nums.length;
        if (l == 1)
        {
            return true;
        }
        int thisStart = 0;
        int maxNextJumpD = 0;
        int lastStart = 0;
        while (thisStart < l - 1)
        {
            boolean flag = false;
            for (int j = maxNextJumpD; lastStart <= j; --j)
            {
                if (j + nums[j] > maxNextJumpD)
                {
                    maxNextJumpD = j + nums[j];
                    flag = true;
                }
            }
            if (!flag)
            {
                return false;
            }
            lastStart = thisStart;
            thisStart = maxNextJumpD;
        }
        return true;
    }
}
