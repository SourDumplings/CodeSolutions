/*
 * @Author: SourDumplings
 * @Date: 2019-10-11 13:49:33
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/sum-of-square-numbers/
 */

class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        int r = sqrt(c);
        for (int i = 0; i <= r; i++)
        {
            int j = sqrt(c - i * i);
            if (j * j + i * i == c)
            {
                return true;
            }
        }
        return false;
    }
};