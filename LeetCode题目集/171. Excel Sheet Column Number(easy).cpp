/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: 
 * @Date: 2019-05-06 21:09:33
 */

class Solution
{
public:
    int titleToNumber(string s)
    {
        int res = 0, e = s.length() - 1;
        for (char c : s)
        {
            res += (c - 'A' + 1) * pow(26, e);
            --e;
        }
        return res;
    }
};