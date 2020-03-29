/*
 * @Author: SourDumplings
 * @Date: 2020-03-29 10:52:06
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/merge-intervals/
 */

class Solution
{
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        int n = intervals.size();
        vector<vector<int>> res;
        if (n == 0)
        {
            return res;
        }
        
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &p1, const vector<int> &p2) { return p1[0] < p2[0]; });
        vector<int> thisTempPair = intervals[0];
        for (int i = 1; i < n; ++i)
        {
            if (thisTempPair[1] >= intervals[i][0])
            {
                thisTempPair[1] = max(intervals[i][1], thisTempPair[1]);
            }
            else
            {
                res.push_back(std::move(thisTempPair));
                thisTempPair = intervals[i];
            }
        }
        res.push_back(std::move(thisTempPair));

        return res;
    }
};