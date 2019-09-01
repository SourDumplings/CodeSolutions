/*
 * @Author: SourDumplings
 * @Date: 2019-09-01 22:59:41
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/ugly-number/
 */

class Solution
{
public:
    bool isUgly(int num)
    {
        if (num <= 0)
        {
            return false;
        }

        while (num > 1)
        {
            if (num % 2 == 0)
                num /= 2;
            else if (num % 3 == 0)
            {
                num /= 3;
            }
            else if (num % 5 == 0)
            {
                num /= 5;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};