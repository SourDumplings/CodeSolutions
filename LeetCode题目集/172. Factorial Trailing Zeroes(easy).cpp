/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: 
 * @Date: 2019-05-08 17:50:52
 * 
 * 算法思路：
 * 就是看一下n里面有几个5，比如3里面没有5，里面有1个5,1个5就会产出1个0
 * 但是注意这个5是递归的，比如26里面含有25，可以产生2个5，
 * 那么相当于26的阶乘里面的0的个数为26 / 5 + 26 / 25 = 6
 */

class Solution
{
public:
    int trailingZeroes(int n)
    {
        long five = 5;
        int res = 0;
        while (five <= n && five < INT_MAX)
        {
            res += n / five;
            five *= 5;
        }
        return res;
    }
};