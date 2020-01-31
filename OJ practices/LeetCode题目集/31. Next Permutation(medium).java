/*
 * @Author: SourDumplings
 * @Date: 2020-01-30 20:15:26
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/next-permutation/
 * 
 * 首先从右往左找到第一个降序的元素即为 a
 * 再从 a 向右找到最小的比 a 大的元素 b
 * 将 a 和 b 换位置
 * 将当前 b 右边的元素序列逆序即可得到结果
 * 详见：https://leetcode.com/problems/next-permutation/solution/
 */

class Solution
{
    public void nextPermutation(int[] nums)
    {
        int l = nums.length;
        int ai = l - 1;
        for (; ai > 0; ai--)
        {
            if (nums[ai - 1] < nums[ai])
            {
                break;
            }
        }
        if (ai == 0)
        {
            reverse(nums, 0);
            return;
        }

        --ai;
        int bi = ai + 1;
        for (; bi < l; bi++)
        {
            if (nums[bi] <= nums[ai])
            {
                break;
            }
        }
        --bi;
        int temp = nums[ai];
        nums[ai] = nums[bi];
        nums[bi] = temp;
        reverse(nums, ai + 1);
    }

    private void reverse(int[] nums, int b)
    {
        int l = nums.length;
        int e = (l + b) / 2;
        for (int i = b; i < e; i++)
        {
            int temp = nums[i];
            nums[i] = nums[l - i + b - 1];
            nums[l - i + b - 1] = temp;
        }
    }
}