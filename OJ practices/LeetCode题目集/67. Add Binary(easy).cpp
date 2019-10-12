/*
 @Date    : 2019-01-26 21:53:59
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/add-binary/
 */

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string res;
        int pa = a.length() - 1, pb = b.length() - 1;
        int lastAdd = 0;
        char thisD;
        while (pa >= 0 && pb >= 0)
        {
            if (a[pa] - '0' + b[pb] - '0' + lastAdd >= 2)
            {
                thisD = a[pa] - '0' + b[pb] - '0' + lastAdd - 2 + '0';
                lastAdd = 1;
            }
            else
            {
                thisD = a[pa] - '0' + b[pb] - '0' + lastAdd + '0';
                lastAdd = 0;
            }
            res += thisD;
            --pa;
            --pb;
        }
        while (pa >= 0)
        {
            if (a[pa] - '0' + lastAdd >= 2)
            {
                thisD = a[pa] - '0' + lastAdd - 2 + '0';
                lastAdd = 1;
            }
            else
            {
                thisD = a[pa] - '0' + lastAdd + '0';
                lastAdd = 0;
            }
            res += thisD;
            --pa;
        }
        while (pb >= 0)
        {
            if (b[pb] - '0' + lastAdd >= 2)
            {
                thisD = b[pb] - '0' + lastAdd - 2 + '0';
                lastAdd = 1;
            }
            else
            {
                thisD = b[pb] - '0' + lastAdd + '0';
                lastAdd = 0;
            }
            res += thisD;
            --pb;
        }
        if (lastAdd == 1)
        {
            res += '1';
        }
        reverse(res.begin(), res.end());
        return std::move(res);
    }
};
