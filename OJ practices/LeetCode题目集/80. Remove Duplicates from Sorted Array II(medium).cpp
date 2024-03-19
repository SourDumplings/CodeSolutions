/**
 * @file 80. Remove Duplicates from Sorted Array II(medium).cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 移除有序数组中重复数大于 2 的元素，双指针法
 * @version 1.0.0
 * @date 2024-03-19
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
 * 
 * 
 * 复杂度：空间 O(1) 时间 O(n)
 */

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
        {
            return n;
        }

        int l = 1;
        bool canRepeat = nums[0] != nums[1];
        for (int r = 2; r < n; r++)
        {
            if (nums[r] != nums[l])
            {
                nums[++l] = nums[r];
                canRepeat = true;
            }
            else if (canRepeat)
            {
                nums[++l] = nums[r];
                canRepeat = false;
            }

        }
        return l + 1;

    }
};