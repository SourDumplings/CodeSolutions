/*
 * @Author: SourDumplings
 * @Date: 2019-08-31 11:02:23
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/add-digits/
 */

class Solution
{
    public int addDigits(int num)
    {
        int r = num % 9;
        if (r == 0 && num != 0)
        {
            return 9;
        }
        return r;
    }
}