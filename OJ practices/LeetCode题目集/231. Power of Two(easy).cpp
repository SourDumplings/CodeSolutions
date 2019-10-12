/*
 * @Author: SourDumplings
 * @Date: 2019-08-25 22:52:07
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/power-of-two/
 * 
 * 所有的2的幂的二进制形式都是一个1后面全是0
 * 它和它减1的数做位与运算一定得0
 */

class Solution
{
public:
    bool isPowerOfTwo(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        return (n & (n - 1)) == 0;
    }
};
