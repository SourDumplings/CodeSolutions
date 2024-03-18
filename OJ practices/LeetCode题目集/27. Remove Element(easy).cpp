/**
 * @brief 移除元素，双指针法
 * 
 */

/*
https://leetcode.com/problems/remove-element/
https://leetcode.cn/problems/remove-element/solutions/730203/yi-chu-yuan-su-by-leetcode-solution-svxi/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int n = nums.size();
        int l = 0;
        for (int r = 0; r < n; ++r)
        {
            if (nums[r] != val)
            {
                nums[l++] = nums[r];
            }
        }
        return l;
    }
};

