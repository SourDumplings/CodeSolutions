/*
 * @Author: SourDumplings
 * @Date: 2021-01-13 18:40:39
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/product-of-array-except-self/
 * 
 * 就是记录一边的总乘积，然后另一边开始遍历，一个变量记住动态总乘积即可
 * 复杂度：时间 O(n) 空间 O(1)，不考虑结果数组
 */

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res(n, 1);
        for (int i = 1; i < n; ++i)
        {
            res[i] = res[i - 1] * nums[i - 1];
        }
        int x = 1;
        for (int i = n - 2; 0 <= i; --i)
        {
            x *= nums[i + 1];
            res[i] *= x;
        }
        return res;
    }
};