/*
 * @Author: SourDumplings
 * @Date: 2019-10-04 14:48:59
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/student-attendance-record-i/
 */

class Solution
{
    public boolean checkRecord(String s)
    {
        int l = 0, a = 0;
        char lastC = 'a';
        boolean isFirst = true;
        int n = s.length();
        for (int i = 0; i != n; ++i)
        {
            char c = s.charAt(i);
            if (isFirst)
            {
                isFirst = false;
                lastC = c;
            }
            else if (c != lastC)
            {
                l = 0;
                lastC = c;
            }

            if (c == 'L')
            {
                ++l;
            }
            else if (c == 'A')
            {
                ++a;
            }
            if (l > 2 || a > 1)
            {
                return false;
            }
        }
        if (l > 2 || a > 1)
        {
            return false;
        }
        return true;
    }
}