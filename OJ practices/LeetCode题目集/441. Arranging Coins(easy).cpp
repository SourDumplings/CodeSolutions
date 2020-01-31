/*
 * @Author: SourDumplings
 * @Date: 2019-09-25 19:41:29
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/arranging-coins/
 * 
 * 假设n刚好能容纳x行
 * 则(1 + x) * x / 2 = n => x^2 + x - 2n = 0
 * x = (-1 + sqrt(1 + 8n)) / 2，取整即可
 */

class Solution
{
public:
    int arrangeCoins(int n)
    {
        return (int)((-1 + sqrt(1 + 8 * (double)n)) / 2);
    }
};