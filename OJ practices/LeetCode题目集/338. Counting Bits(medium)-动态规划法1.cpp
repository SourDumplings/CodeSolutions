/*
 * @Author: SourDumplings
 * @Date: 2021-04-08 21:44:26
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/counting-bits/
 * 
 * 参考：https://leetcode-cn.com/problems/counting-bits/solution/bi-te-wei-ji-shu-by-leetcode-solution-0t1i/
 * 
 * x & (x - 1) 会将 x 的最低位的 1 变为 0
 * 如果 x 是 2 的倍数，当且仅当 x & (x - 1) = 0
 * 此时如果 x 的最高位也是 y 的最高位，必有 oneNum[y] = oneNum[y - x] + 1 
 */

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> res(num + 1);
        int highBit = 0; // 记录代表当前最高位的 2 的倍数
        res[0] = 0;
        for (int i = 1; i <= num; ++i)
        {
            if ((i & (i - 1)) == 0)
            {
                highBit = i;
            }
            res[i] = res[i - highBit] + 1;
        }
        return res;
    }
};

