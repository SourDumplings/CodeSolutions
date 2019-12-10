/*
 * @Autor: SourDumplings
 * @Date: 2019-12-10 08:46:16
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/median-of-two-sorted-arrays/
 * 
 * 算法：参考：
 * https://blog.csdn.net/qq_28466517/article/details/79810809
 * https://www.jianshu.com/p/21f570caca89
 * 
首先将两个数组分成两部分：
left_part | right_part 
A[0], A[1], ..., A[i-1] | A[i], A[i+1], ..., A[m-1] 
B[0], B[1], ..., B[j-1] | B[j], B[j+1], ..., B[n-1]

其中必须满足：
a.左边部分的数的个数之和和右边相等
b.A[i-1] <= B[j], B[j-1] <= A[i]
那么中位数一定在 A[i-1]，B[j]，B[j-1]，A[i] 这4个数中

分成两种情况讨论：
1.m+n 为奇数时，把中位数归于左半部分，中位数是 max(A[i-1], B[j-1])
把此时条件 a 可以翻译成： i + j == m - i + n - j + 1
2.m+n 为偶数时，中位数是 (max(A[i-1], B[j-1]) + min(A[i], B[j])) / 2
此时条件 a 可以翻译成： i + j == m - i + n - j

先用二分法确定 i，然后根据条件 a 确定 j。

 */

class Solution
{
    public double findMedianSortedArrays(int[] nums1, int[] nums2)
    {
        int m = nums1.length;
        int n = nums2.length;

        // 始终让 m <= n
        if (n < m)
        {
            return findMedianSortedArrays(nums2, nums1);
        }

        int lo = 0, hi = m;
        double res = 0.0;
        while (lo <= hi) // 注意判断条件是小于等于，不是严格的小于，因为可以一个数组的一边为空
        {
            int i = (lo + hi) / 2;
            int j = (m + n + 1) / 2 - i; // 奇偶都是这个

            // 对于划分点移动后边界条件的控制，因为有可能数组一边为空
            int maxLeftA = i == 0 ? Integer.MIN_VALUE : nums1[i - 1];
            int maxLeftB = j == 0 ? Integer.MIN_VALUE : nums2[j - 1];
            int minRightA = i == m ? Integer.MAX_VALUE : nums1[i];
            int minRightB = j == n ? Integer.MAX_VALUE : nums2[j];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA)
            {
                if ((m + n) % 2 == 0)
                {
                    res = (Math.max(maxLeftA, maxLeftB) + Math.min(minRightA, minRightB)) / 2.0;
                }
                else
                {
                    res = Math.max(maxLeftA, maxLeftB);
                }
                break;
            }
            else if (minRightA < maxLeftB)
            {
                // 划分点需要右移
                lo = i + 1;
            }
            else
            {
                hi = i;
            }
        }
        return res;
    }
}