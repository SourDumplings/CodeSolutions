/*
 * @Autor: SourDumplings
 * @Date: 2019-10-15 08:30:18
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/repeated-string-match/
 */

class Solution
{
public:
    int repeatedStringMatch(string A, string B)
    {
        int la = A.length();
        int lb = B.length();
        string temp(A);
        int res = 1;
        while (temp.length() < la + lb && temp.find(B) == string::npos)
        {
            ++res;
            temp += A;
        }
        if (temp.find(B) != string::npos)
        {
            return res;
        }
        else
        {
            return -1;
        }
    }
};