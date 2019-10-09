/*
 * @Autor: SourDumplings
 * @Date: 2019-10-09 16:26:27
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/minimum-index-sum-of-two-lists/
 */

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, int> m1;
        int l1 = list1.size();
        int l2 = list2.size();
        for (int i = 0; i < l1; i++)
        {
            m1[list1[i]] = i;
        }
        int minI = __INT32_MAX__;
        vector<string> res;
        for (int i = 0; i < l2; i++)
        {
            string s = list2[i];
            if (m1.find(s) != m1.end())
            {
                int i1 = m1[s];
                if (i1 + i < minI)
                {
                    res.clear();
                    res.push_back(s);
                    minI = i1 + i;
                }
                else if (i1 + i == minI)
                {
                    res.push_back(s);
                }
            }
        }
        return res;
    }
};