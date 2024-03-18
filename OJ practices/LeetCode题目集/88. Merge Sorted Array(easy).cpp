/**
 * @brief 合并有序数组，逆向双指针法
 * 时间复杂度 O(m+n) 空间复杂度 O(1)
 * 
 */

/*
https://leetcode.com/problems/merge-sorted-array/
https://leetcode.cn/problems/merge-sorted-array/solutions/666608/he-bing-liang-ge-you-xu-shu-zu-by-leetco-rrb0/?envType=study-plan-v2&envId=top-interview-150
 */

#include <vector>

using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (0 <= i && 0 <= j)
        {
            if (nums1[i] < nums2[j])
            {
                nums1[k] = nums2[j];
                --j;
            }
            else
            {
                nums1[k] = nums1[i];
                --i;
            }
            --k;
        }
        while (0 <= i)
        {
            nums1[k--] = nums1[i--];
        }
        while (0 <= j)
        {
            nums1[k--] = nums2[j--];
        }
        
    }
};