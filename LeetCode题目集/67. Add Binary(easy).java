/**
 * @Date    : 2019-01-26 22:46:17
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * https://leetcode.com/problems/add-binary/
*/

import java.util.Vector;

class Solution
{
    public String addBinary(String a, String b)
    {
        Vector res = new Vector();
        int pa = a.length() - 1, pb = b.length() - 1;
        int lastAdd = 0;
        char thisD;
        while (pa >= 0 && pb >= 0)
        {
            if ((int)(a.charAt(pa) - '0') + (int)(b.charAt(pb) - '0') + lastAdd>= 2)
            {
                thisD = (char)((int)(a.charAt(pa) - '0') + (int)(b.charAt(pb) - '0') +
                    lastAdd - 2 + 48);
                lastAdd = 1;
            }
            else
            {
                thisD = (char)((int)(a.charAt(pa) - '0') + (int)(b.charAt(pb) - '0') +
                    lastAdd + 48);
                lastAdd = 0;
            }
            res.add(thisD);
            --pa;
            --pb;
        }
        while (pa >= 0)
        {
            if ((int)(a.charAt(pa) - '0') + lastAdd >= 2)
            {
                thisD = (char)((int)(a.charAt(pa) - '0') + lastAdd - 2 + 48);
                lastAdd = 1;
            }
            else
            {
                thisD = (char)((int)(a.charAt(pa) - '0') + lastAdd + 48);
                lastAdd = 0;
            }
            res.add(thisD);
            --pa;
        }
        while (pb >= 0)
        {
            if ((int)(b.charAt(pb) - '0') + lastAdd >= 2)
            {
                thisD = (char)((int)(b.charAt(pb) - '0') + lastAdd - 2 + 48);
                lastAdd = 1;
            }
            else
            {
                thisD = (char)((int)(b.charAt(pb) - '0') + lastAdd + 48);
                lastAdd = 0;
            }
            res.add(thisD);
            --pb;
        }
        if (lastAdd == 1)
        {
            res.add('1');
        }
        Collections.reverse(res);
        int n = res.size();
        StringBuffer ret = new StringBuffer(n);
        for (int i = 0; i != n; ++i)
        {
            ret.append(String.valueOf(res.get(i)));
        }
        return ret.toString();
    }
}


