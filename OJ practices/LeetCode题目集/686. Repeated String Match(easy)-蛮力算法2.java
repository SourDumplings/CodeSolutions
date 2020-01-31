/*
 * @Author: SourDumplings
 * @Date: 2019-10-15 08:58:03
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/repeated-string-match/
 */

class Solution
{
    public int repeatedStringMatch(String A, String B)
    {
        int n = B.length() / A.length() + 2;
        StringBuilder sb = new StringBuilder(A);
        for (int i = 0; i < n; i++)
        {
            if (sb.indexOf(B) != -1)
            {
                return i + 1;
            }
            sb.append(A);
        }
        return -1;
    }
}