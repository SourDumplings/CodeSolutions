/*
 * @Author: SourDumplings
 * @Date: 2021-06-05 07:40:13
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/interleaving-string/
 */

class Solution
{
private:
    bool judge(const string &s1,
               const string &s2,
               const string &s3,
               int b1,
               int b2,
               int b3,
               int l1,
               int l2,
               int l3)
    {
        if (b3 == l3)
        {
            return b1 == l1 && b2 == l2;
        }
        else if (b1 == l1 && b2 == l2)
        {
            return false;
        }
        else if (b1 == l1)
        {
            if (s2[b2] != s3[b3])
            {
                return false;
            }
            else
            {
                return judge(s1, s2, s3, b1, b2 + 1, b3 + 1, l1, l2, l3);
            }
        }
        else if (b2 == l2)
        {
            if (s1[b1] != s3[b3])
            {
                return false;
            }
            else
            {
                return judge(s1, s2, s3, b1 + 1, b2, b3 + 1, l1, l2, l3);
            }
        }
        else
        {
            if (s1[b1] == s3[b3] && s2[b2] == s3[b3])
            {
                return judge(s1, s2, s3, b1, b2 + 1, b3 + 1, l1, l2, l3)
                    || judge(s1, s2, s3, b1 + 1, b2, b3 + 1, l1, l2, l3);
            }
            else if (s1[b1] == s3[b3])
            {
                return judge(s1, s2, s3, b1 + 1, b2, b3 + 1, l1, l2, l3);
            }
            else if (s2[b2] == s3[b3])
            {
                return judge(s1, s2, s3, b1, b2 + 1, b3 + 1, l1, l2, l3);
            }
        }
        return false;
    }
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if (l3 != l1 + l2)
        {
            return false;
        }
        return judge(s1, s2, s3, 0, 0, 0, l1, l2, l3);
    }
};