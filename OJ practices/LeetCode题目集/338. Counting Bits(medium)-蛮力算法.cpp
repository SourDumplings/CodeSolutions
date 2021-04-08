/*
 * @Author: SourDumplings
 * @Date: 2021-04-08 21:22:03
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/counting-bits/
 * 
 * 参考：https://leetcode-cn.com/problems/counting-bits/solution/bi-te-wei-ji-shu-by-leetcode-solution-0t1i/
 * 
 * 利用位运算的技巧，可以在一定程度上提升计算速度。
 * 按位与运算（\&&）的一个性质是：对于任意整数 xx，令 x=x~\&~(x-1)x=x & (x−1)，
 * 该运算将 xx 的二进制表示的最后一个 11 变成 00。因此，对 xx 重复该操作，
 * 直到 xx 变成 00，则操作次数即为 xx 的「一比特数」。

 */

class Solution
{
private:
    int get_ones(int x)
    {
        int res = 0;
        while (x)
        {
            x = x & (x - 1);
            ++res;
        }
        return res;
    }
public:
    vector<int> countBits(int num)
    {
        vector<int> res(num + 1);
        for (int i = 0; i <= num; ++i)
        {
            res[i] = get_ones(i);
        }
        return res;
    }
};