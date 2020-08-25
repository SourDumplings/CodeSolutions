/*
 * @Author: SourDumplings
 * @Date: 2020-08-25 09:39:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/search-in-rotated-sorted-array-ii/
 * 
 * 参考 ：https://www.cnblogs.com/grandyang/p/4325840.html
 * 这道是之前那道 Search in Rotated Sorted Array 的延伸，
 * 现在数组中允许出现重复数字，这个也会影响我们选择哪半边继续搜索，
 * 由于之前那道题不存在相同值，我们在比较中间值和最右值时就完全符合之前所说的规律：
 * 如果中间的数小于最右边的数，则右半段是有序的，若中间数大于最右边数，
 * 则左半段是有序的。而如果可以有重复值，就会出现来面两种情况，
 * [3 1 1] 和 [1 1 3 1]，对于这两种情况中间值等于最右值时，
 * 目标值3既可以在左边又可以在右边，那怎么办么，对于这种情况其实处理非常简单，
 * 只要把最右值向左一位即可继续循环，如果还相同则继续移，直到移到不同值为止，
 * 然后其他部分还采用 Search in Rotated Sorted Array 中的方法
 */

class Solution
{
    public boolean search(int[] nums, int target)
    {
        int l = nums.length;
        int lo = 0, hi = l;
        while (lo < hi)
        {
            int mi = (lo + hi) / 2;
            if (nums[mi] == target)
            {
                return true;
            }
            if (nums[mi] < nums[hi - 1])
            {
                if (nums[mi] < target && target <= nums[hi - 1])
                {
                    lo = mi + 1;
                }
                else
                {
                    hi = mi;
                }
            }
            else if (nums[hi - 1] < nums[mi])
            {
                if (nums[lo] <= target && target < nums[mi])
                {
                    hi = mi;
                }
                else
                {
                    lo = mi + 1;
                }
            }
            else
            {
                --hi;
            }
        }
        return false;
    }
}
