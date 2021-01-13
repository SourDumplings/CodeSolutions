/*
 * @Author: SourDumplings
 * @Date: 2021-01-13 18:40:39
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/product-of-array-except-self/
 */

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n,1);
        for (int j = n - 1; j >= 0; --j)
        {
            if (j == n - 1)
            {
                res[j] = 1;
            }
            else
            {
                res[j] = nums[j + 1] * res[j + 1];
            }
        }
        int pre_product = 1;
        for (int i = 0; i < n; ++i)
        {
            if (i > 0)
            {
                res[i] *= pre_product;
            }
            pre_product *= nums[i];
        }
        return res;
    }
};