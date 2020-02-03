import java.util.Arrays;

/*
 * @Author: SourDumplings
 * @Date: 2020-02-03 10:58:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
 */

class Solution
{
    public int[] searchRange(int[] nums, int target)
    {
        int b = binarySearch(nums, target);
        int[] res =
        { -1, -1 };
        if (b == -1)
        {
            return res;
        }
        int l = nums.length;
        int e = b;
        for (; e < l && nums[e] == target; e++)
            ;
        for (; 0 <= b && nums[b] == target; --b)
            ;
        res[0] = b + 1;
        res[1] = e - 1;
        return res;
    }

    private int binarySearch(int[] nums, int target)
    {
        if (nums.length == 0)
        {
            return -1;
        }
        int lo = 0;
        int hi = nums.length - 1;
        while (lo < hi)
        {
            int mi = (lo + hi) / 2;
            if (nums[mi] == target)
            {
                return mi;
            }
            else if (nums[mi] < target)
            {
                lo = mi + 1;
            }
            else
            {
                hi = mi;
            }
        }
        return nums[lo] == target ? lo : -1;
    }
}