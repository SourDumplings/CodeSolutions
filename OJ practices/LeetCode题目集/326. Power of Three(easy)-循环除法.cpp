/*
 * @Author: SourDumplings
 * @Date: 2019-09-10 20:21:54
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/power-of-three/
 */

class Solution
{
public:
    bool isPowerOfThree(int n)
    {
        while (n > 1 && n % 3 == 0)
        {
            n /= 3;
        }
        return n == 1;
    }
};