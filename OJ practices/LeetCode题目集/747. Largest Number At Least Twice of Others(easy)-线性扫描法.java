/*
 * @Autor: SourDumplings
 * @Date: 2019-11-03 16:32:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/largest-number-at-least-twice-of-others/
 * 
 * 依照题意，只需线性扫描两次，得到最大值和次大值即可。。
 */

class Solution
{
    public int dominantIndex(int[] nums)
    {
        int maxIndex = 0, secondMaxIndex = -1;
        int l = nums.length;
        if (l < 2)
        {
            return 0;
        }
        for (int i = 0; i < l; i++)
        {
            if (nums[i] > nums[maxIndex])
            {
                maxIndex = i;
            }
        }
        for (int i = 0; i < l; i++)
        {
            if ((secondMaxIndex == -1 || nums[i] > nums[secondMaxIndex]) && nums[i] < nums[maxIndex])
            {
                secondMaxIndex = i;
            }
        }
        return nums[maxIndex] >= nums[secondMaxIndex] * 2 ? maxIndex : -1;
    }
}
