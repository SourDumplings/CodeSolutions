/*
 * @Author: SourDumplings
 * @Date: 2019-10-11 10:21:47
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/maximum-product-of-three-numbers/
 * 
 * 三个整数乘积最大，考虑到负数，只有可能是两种情况
 * 1.三个最大的数相乘
 * 2.一个最大数乘以两个最小数（绝对值最大的负数）
 * 更新最大最小值时采用递进法，时间复杂度O(n)，空间复杂度O(1)
 */

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int max1, max2, max3, min1, min2;
        max1 = max2 = max3 = -2147483648;
        min1 = min2 = 2147483647;
        for (auto &&i : nums)
        {
            if (i <= min1)
            {
                min2 = min1;
                min1 = i;
            }
            else if (i <= min2)
            {
                min2 = i;
            }
            if (i >= max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = i;
            }
            else if (i >= max2)
            {
                max3 = max2;
                max2 = i;
            }
            else if (i >= max3)
            {
                max3 = i;
            }
        }
        return max(min1 * min2 * max1, max1 * max2 * max3);
    }
};