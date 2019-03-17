/**
 * @Date    : 2019-01-24 20:26:00
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * https://leetcode.com/problems/plus-one/
*/

class Solution
{
    public int[] plusOne(int[] digits)
    {
        return doAdd(digits, digits.length - 1);
    }

    public int[] doAdd(int[] digits, int d)
    {
        if (d == -1)
        {
            int[] res = Arrays.copyOf(digits, digits.length+1);
            int l = res.length;
            for (int i = l - 1; i != 0; --i)
            {
                res[i] = res[i-1];
            }
            res[0] = 1;
            return res;
        }
        else
        {
            if (digits[d] == 9)
            {
                digits[d] = 0;
                return doAdd(digits, d - 1);
            }
            else
            {
                ++digits[d];
                return digits;
            }
        }
    }
}
