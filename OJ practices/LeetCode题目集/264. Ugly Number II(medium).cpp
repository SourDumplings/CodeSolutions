/*
 * @Author: SourDumplings
 * @Date: 2021-01-17 09:20:57
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/ugly-number-ii/
 */

class Solution
{
public:
    int nthUglyNumber(int n)
    {
        // 这三个指针可理解为指向乘以对应因子得到下一个数的位置
        int i2 = 0, i3 = 0, i5 = 0;
        int nums[1690];
        nums[0] = 1;
        for (int i = 1; i < 1690; ++i)
        {
            int ugly = min(min(nums[i2] * 2, nums[i3] * 3), nums[i5] * 5);
            nums[i] = ugly;
            if (ugly == nums[i2] * 2)
            {
                ++i2;
            }
            if (ugly == nums[i3] * 3)
            {
                ++i3;
            }
            if (ugly == nums[i5] * 5)
            {
                ++i5;
            }
        }
        return nums[n - 1];
    }
};