/*
 * @Author: SourDumplings
 * @Date: 2020-08-20 09:43:49
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/decode-ways/
 */

class Solution
{
    public int numDecodings(String s)
    {
        int l = s.length();
        int[] res = new int[l + 1];
        if (l == 0)
        {
            return 0;
        }
        res[0] = 1;
        for (int i = 1; i <= l; i++)
        {
            if (s.charAt(i - 1) == '0')
            {
                res[i - 1] = 0;
            }
            if (1 < i && (s.charAt(i - 2) == '1' || s.charAt(i - 2) == '2' && s.charAt(i - 1) <= '6'))
            {
                res[i] = res[i - 1] + res[i - 2];
            }
            else
            {
                res[i] = res[i - 1];
            }
        }
        return res[l];
    }
}