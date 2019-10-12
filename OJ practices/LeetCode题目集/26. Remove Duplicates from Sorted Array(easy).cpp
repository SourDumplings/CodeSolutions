/*
 @Date    : 2019-01-10 16:28:04
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/remove-duplicates-from-sorted-array/
 */

class Solution
{
public:
    int removeDuplicates(vector<int>& nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        int lastNum = nums[0];
        int k = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] != lastNum)
            {
                nums[k++] = lastNum = nums[i];
            }
        }
        nums.erase(nums.begin() + k, nums.end());
        return nums.size();
    }
};

