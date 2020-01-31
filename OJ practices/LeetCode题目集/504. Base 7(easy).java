/*
 * @Author: SourDumplings
 * @Date: 2019-09-28 13:42:05
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/base-7/
 */

class Solution
{
    public String convertToBase7(int num)
    {
        if (num == 0)
        {
            return "0";
        }
        boolean negative = false;
        if (num < 0)
        {
            negative = true;
            num = -num;
        }
        StringBuilder sb = new StringBuilder();
        while (num != 0)
        {
            sb.append((char) (num % 7 + '0'));
            num /= 7;
        }
        if (negative)
        {
            sb.append('-');
        }
        return sb.reverse().toString();
    }
}
