/*
 * @Author: SourDumplings
 * @Date: 2019-08-31 10:53:36
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/add-digits/
 * 
 * 对于任何一个数其各个数位之和能被9整除这个数就能被9整除，同理
 * 这个数除以9的余数和这个数各个数位之和除以9的余数相同。
 * 那么各个数位之和除以9的余数是不变的，和完了再和还是不变，
 * 因此利用这个特性便可以找出那个1位数，特殊情况是能被9整除的情况该1位数是9而不是0，0除外
 */

class Solution
{
public:
    int addDigits(int num)
    {
        int r = num % 9;
        if (r == 0 && num != 0)
        {
            return 9;
        }
        return r;
    }
};