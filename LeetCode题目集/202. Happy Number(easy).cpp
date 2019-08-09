/*
 * @Author: SourDumplings
 * @Date: 2019-08-09 11:24:05
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/happy-number/
 */

class Solution
{
public:
    bool isHappy(int n)
    {
        int checkNum = 100;
        while (checkNum--)
        {
            if (check(n))
            {
                return true;
            }
        }
        return false;
    }

    bool check(int &n)
    {
        string s = to_string(n);
        int sum = 0;
        for (char d : s)
        {
            int dd = d - '0';
            sum += dd * dd;
        }
        if ((n = sum) == 1)
        {
            return true;
        }
        return false;
    }
};