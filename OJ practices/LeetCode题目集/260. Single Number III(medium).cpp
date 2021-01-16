/*
 * @Author: SourDumplings
 * @Date: 2021-01-16 11:32:26
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/single-number-iii/
 * 
 * 参考：https://leetcode-cn.com/problems/single-number-iii/solution/java-yi-huo-100-yao-shi-kan-bu-dong-wo-jiu-qu-chu-/
 * 假设两个数为 A、B
 * 对全数组进行亦或，得到 A ^ B = C
 * 然后从低到高位看 C 哪一位是 1，说明 A 和 B 在这一位是不同的
 * 根据这一位是否是 1 将原数组便可以分成两组，A 和 B 也就会被分在不同组了
 * 然后用亦或的方法就可以找到 A 和 B
 */

class Solution
{
public:
    vector<int> singleNumber(vector<int> &nums)
    {
        unsigned temp = 0;
        int n = nums.size();
        for (int i = 0; i < n; ++i)
        {
            temp ^= nums[i];
        }
        unsigned mask = 1;
        for (int j = 0; j < 32; ++j)
        {
            if (mask & temp)
            {
                break;
            }
            mask <<= 1;
        }
        vector<int> res(2);
        res[0] = res[1] = 0;
        for (int k = 0; k < n; ++k)
        {
            if ((nums[k] & mask) == 0)
            {
                res[0] ^= nums[k];
            }
            else
            {
                res[1] ^= nums[k];
            }
        }
        return res;
    }
};