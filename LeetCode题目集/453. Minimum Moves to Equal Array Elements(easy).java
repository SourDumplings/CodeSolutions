/*
 * @Autor: SourDumplings
 * @Date: 2019-09-26 08:17:33
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
 */

class Solution
{
    public int minMoves(int[] nums)
    {
        int sum = 0;
        int min = Integer.MAX_VALUE;
        for (int i : nums)
        {
            sum += i;
            if (i < min)
            {
                min = i;
            }
        }
        return sum - min * nums.length;
    }
}