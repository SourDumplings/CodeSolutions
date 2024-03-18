/**
 * @brief 移除有序数组中的重复元素，双指针法
 * 
 */

/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }

        int l = 1;
        for (int r = 1; r < n; r++)
        {
            if (nums[l - 1] != nums[r])
            {
                nums[l++] = nums[r];
            }
        }
        return l;
    }
};
