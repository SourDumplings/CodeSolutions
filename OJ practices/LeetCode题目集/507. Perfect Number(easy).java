/*
 * @Author: SourDumplings
 * @Date: 2019-09-29 07:57:00
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/perfect-number/
 */

class Solution
{
    public boolean checkPerfectNumber(int num)
    {
        if (num <= 1)
        {
            return false;
        }

        int n = (int) (Math.sqrt(num));
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            if (num % i == 0)
            {
                sum += i;
                if (i != 1)
                {
                    sum += num / i;
                }
            }
        }
        return num == sum;
    }
}