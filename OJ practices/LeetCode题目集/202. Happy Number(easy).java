/*
 * @Author: SourDumplings
 * @Date: 2019-08-09 11:32:24
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/happy-number/
 */

class Solution
{
    public boolean isHappy(int n)
    {
        int repeatNum = 100;
        while (repeatNum-- != 0)
        {
            if ((n = doCheck(n)) == 1)
                return true;

        }
        return false;
    }

    private int doCheck(int n)
    {
        String num = new Integer(n).toString();
        int l = num.length();
        int res = 0;
        for (int i = 0; i < l; i++)
        {
            Character d = num.charAt(i);
            int digit = Integer.parseInt(d.toString());
            res += digit * digit;
        }
        return res;
    }
}