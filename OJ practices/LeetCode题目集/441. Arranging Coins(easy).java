/*
 * @Author: SourDumplings
 * @Date: 2019-09-25 19:48:29
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/arranging-coins/
 */

class Solution
{
    public int arrangeCoins(int n)
    {
        return (int) ((-1 + Math.sqrt(1 + 8 * (double) n)) / 2);
    }
}