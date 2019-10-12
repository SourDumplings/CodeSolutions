/*
 * @Autor: SourDumplings
 * @Date: 2019-09-13 23:05:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/intersection-of-two-arrays/
 */

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        set<int> s1, s2;
        for (auto &&i : nums1)
        {
            s1.insert(i);
        }
        for (auto &&i : nums2)
        {
            s2.insert(i);
        }
        vector<int> res;
        for (auto &&i : s1)
        {
            if (s2.find(i) != s2.end())
            {
                res.push_back(i);
            }
        }
        return res;
    }
};
