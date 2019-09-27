/*
 * @Autor: SourDumplings
 * @Date: 2019-09-27 15:38:26
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/next-greater-element-i/
 */

class Solution
{
public:
    vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2)
    {
        vector<int> res;
        int l1 = nums1.size(), l2 = nums2.size();
        res.resize(l1);
        fill(res.begin(), res.end(), -1);
        for (int i = 0; i < l1; i++)
        {
            int n1 = nums1[i];
            bool isRight = false;
            for (int j = 0; j < l2; j++)
            {
                if (isRight && nums2[j] > n1)
                {
                    res[i] = nums2[j];
                    break;
                }
                if (nums2[j] == n1)
                {
                    isRight = true;
                }
            }
        }
        return res;
    }
};