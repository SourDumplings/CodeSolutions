/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/single-number/
 * @Date: 2019-03-31 19:11:50
 * 
 * a ^ a = 0, a ^ 0 = a, (a ^ a) ^ b = b，并且异或运算满足交换律和结合律
 * 故我们将所有的数异或起来即可
 */

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        int ret = 0;
        for (auto &i : nums)
        {
            ret ^= i;
        }

        return ret;
    }
};