/*
 * @Author: SourDumplings
 * @Date: 2019-09-27 13:48:55
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/license-key-formatting/
 */

class Solution
{
public:
    string licenseKeyFormatting(string S, int K)
    {
        string s;
        int L = S.length();
        for (int i = 0; i < L; ++i)
        {
            char c = S[i];
            if (isalnum(c))
            {
                s += toupper(c);
            }
        }
        int l = s.length();
        int first = l % K;
        bool isFirst = (first != 0);
        string res;
        for (int i = 0; i < l; i++)
        {
            res += s[i];
            if (isFirst)
            {
                if (i == first - 1 && K < l)
                {
                    res += '-';
                    isFirst = false;
                }
            }
            else if ((i - first + 1) % K == 0 && i != l - 1)
            {
                res += '-';
            }
        }

        return res;
    }
};