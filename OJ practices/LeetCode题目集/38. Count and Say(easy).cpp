/*
 @Date    : 2019-01-17 10:37:27
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/count-and-say/
 */

class Solution
{
public:
    string countAndSay(int n)
    {
        string res = "";
        for (int i = 0; i < n; ++i)
        {
            doCountAndSay(res);
        }
        return res;
    }

    void doCountAndSay(string &res)
    {
        if (res.empty())
        {
            res = "1";
            return;
        }

        char lastD = res[0];
        int lastCount = 1;
        string newRes = "";
        for (int i = 1; i < res.length(); ++i)
        {
            if (res[i] == lastD)
            {
                ++lastCount;
            }
            else
            {
                newRes += to_string(lastCount) + lastD;
                lastCount = 1;
                lastD = res[i];
            }
        }
        newRes += to_string(lastCount) + lastD;
        res = move(newRes);
        return;
    }
};
