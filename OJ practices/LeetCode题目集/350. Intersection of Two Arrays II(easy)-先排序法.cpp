/*
 * @Author: SourDumplings
 * @Date: 2019-09-14 10:13:30
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/intersection-of-two-arrays-ii/
 */

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        int j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        for (int i = 0; i < n1; i++)
        {
            while (j < n2 && nums2[j] < nums1[i])
                ++j;
            if (j == n2)
            {
                break;
            }
            else if (nums2[j] == nums1[i])
            {
                res.push_back(nums2[j++]);
            }
        }
        return res;
    }
};