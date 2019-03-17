/**
 * @Date    : 2019-01-17 11:12:58
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * https://leetcode.com/problems/count-and-say/
*/

class Solution
{
    String res = "";

    public String countAndSay(int n)
    {
        for (int i = 0; i != n; ++i)
        {
            doCountAndSay();
        }
        return res;
    }

    void doCountAndSay()
    {
        if (res.length() == 0)
        {
            res = "1";
            return;
        }
        char lastD = res.charAt(0);
        int lastCount = 1;
        String newRes = "";
        for (int i = 1; i < res.length(); ++i)
        {
            if (res.charAt(i) == lastD)
            {
                ++lastCount;
            }
            else
            {
                newRes += Integer.toString(lastCount) + Character.toString(lastD);
                lastD = res.charAt(i);
                lastCount = 1;
            }
        }
        newRes += Integer.toString(lastCount) + Character.toString(lastD);
        res = newRes;
        return;
    }
}

