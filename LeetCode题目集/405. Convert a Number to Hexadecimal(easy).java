/*
 * @Autor: SourDumplings
 * @Date: 2019-09-23 09:03:33
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/convert-a-number-to-hexadecimal/
 */

class Solution
{
    public String toHex(int num)
    {
        if (num == 0)
        {
            return "0";
        }

        char[] hex =
        { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };

        char[] res = new char[8];
        for (int i = 0; i < 8; i++)
        {
            res[7 - i] = hex[num & 15];
            num >>= 4;
        }
        int j = 0;
        while (res[j] == '0')
        {
            ++j;
        }
        return String.copyValueOf(res, j, 8 - j);
    }
}