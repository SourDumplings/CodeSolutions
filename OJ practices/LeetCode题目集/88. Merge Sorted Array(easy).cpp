/*
 @Date    : 2019-02-21 22:39:59
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/merge-sorted-array/
 */

class Solution
{
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int j = m - 1, k = n - 1;
        for (int i = n + m - 1; i > -1; --i)
        {
            if (k < 0 || j > -1 && nums1[j] > nums2[k])
                nums1[i] = nums1[j--];
            else
                nums1[i] = nums2[k--];
        }
    }
};
