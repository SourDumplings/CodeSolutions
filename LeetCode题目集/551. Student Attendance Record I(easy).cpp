/*
 * @Autor: SourDumplings
 * @Date: 2019-10-04 14:32:33
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/student-attendance-record-i/
 */

class Solution
{
public:
    bool checkRecord(string s)
    {
        int l = 0, a = 0;
        char lastC;
        bool isFirst = true;
        for (auto &&c : s)
        {
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
};