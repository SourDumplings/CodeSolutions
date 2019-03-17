/*
 @Date    : 2019-01-15 20:52:16
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/search-insert-position/
 */

class Solution
{
public:
    int searchInsert(vector<int>& nums, int target)
    {
        int b = 0, e = nums.size();
        int mi;
        while (b < e)
        {
            mi = (b + e) >> 1;
            target < nums[mi] ? e = mi : b = mi + 1;
        }
        if (b == 0 || nums[b - 1] < target)
        {
            return b;
        }
        else
            return b - 1;
    }
};

