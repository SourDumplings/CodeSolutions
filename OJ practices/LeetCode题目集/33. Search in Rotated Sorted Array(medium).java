/*
 * @Author: SourDumplings
 * @Date: 2020-02-02 17:20:08
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/search-in-rotated-sorted-array/
 *
 * 对于 7 个数组成的数组，旋转结果有以下七种：
0　　1　　2　　 4　　5　　6　　7

7　　0　　1　　 2　　4　　5　　6

6　　7　　0　　 1　　2　　4　　5

5　　6　　7　　 0　　1　　2　　4

4　　5　　6　　7　　0　　1　　2

2　　4　　5　　6　　7　　0　　1

1　　2　　4　　5　　6　　7　　0
注意到不论怎么旋转，其总是由两段有序的序列拼成
如果中间的数比最右边的小，说明右半段是有序的，反之说明是左半段有序
然后只在有序的、可能存在该元素的序列中找
 */

class Solution
{
    private int a, b;

    public int search(int[] nums, int target)
    {
        if (nums.length == 0)
        {
            return -1;
        }
        getSortedPossibleArray(nums, 0, nums.length - 1, target);
        return binarySearch(nums, target);
    }

    private void getSortedPossibleArray(int[] nums, int start, int end, int target)
    {
        if (end < start)
        {
            return;
        }
        int mi = (start + end) / 2;
        int c = nums[mi];

        if (c < nums[end])
        {
            if (c <= target && target <= nums[end])
            {
                a = start;
                b = end;
            }
            else
            {
                getSortedPossibleArray(nums, start, mi - 1, target);
            }
        }
        else
        {
            if (target <= c && nums[start] <= target)
            {
                a = start;
                b = end;
            }
            else
            {
                getSortedPossibleArray(nums, mi + 1, end, target);
            }
        }
    }

    private int binarySearch(int[] nums, int target)
    {
        int lo = a, hi = b;
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
