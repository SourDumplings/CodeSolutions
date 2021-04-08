/*
 * @Author: SourDumplings
 * @Date: 2021-04-08 22:08:45
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/counting-bits
 * 
 * 参考：https://leetcode-cn.com/problems/counting-bits/solution/bi-te-wei-ji-shu-by-leetcode-solution-0t1i/
 * 
 * 如果 x 是奇数，则 oneNum[x] = oneNum[x / 2] + 1
 * 如果 x 是偶数，则 oneNum[x] = oneNum[x / 2]
 */

class Solution
{
public:
    vector<int> countBits(int num)
    {
        vector<int> res(num + 1);
        res[0] = 0;
        for (int i = 1; i <= num; ++i)
        {
            res[i] = res[i >> 1] + i % 2;
        }
        return res;
    }
};