/**
 * @Date    : 2019-02-22 22:10:22
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * https://leetcode.com/problems/merge-sorted-array/
*/

class Solution
{
    public void merge(int[] nums1, int m, int[] nums2, int n)
    {
        int j = m - 1, k = n - 1;
        for (int i = m + n - 1; i > -1; --i)
        {
            if (k < 0 || j > -1 && nums1[j] > nums2[k])
            {
                nums1[i] = nums1[j--];
            }
            else
                nums1[i] = nums2[k--];
        }
    }
}

