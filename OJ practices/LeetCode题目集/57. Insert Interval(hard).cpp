/*
 * @Author: SourDumplings
 * @Date: 2020-03-31 21:59:36
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/insert-interval/
 * 
遍历原数组，如果当前区间和新区间没有交集，则直接存入答案；
如果有交集，便和新区间合并，更新新区间的左右边界；
如果当前区间和新区间无交集且大于新区间，则新区间和后面所有的区间都可存入答案。
 */

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        vector<vector<int>> res;
        int n = intervals.size();
        int i = 0;
        bool flag = false;
        for (; i < n; i++)
        {
            if (intervals[i][1] < newInterval[0])
            {
                res.push_back(std::move(intervals[i]));
            }
            else
            {
                flag = true;
                int start = min(intervals[i][0], newInterval[0]);
                int end = newInterval[1];
                for (; i < n; i++)
                {
                    if (newInterval[1] < intervals[i][0])
                    {
                        break;
                    }
                    end = max(end, intervals[i][1]);
                }
                res.push_back(vector<int>({start, end}));
                for (; i < n; i++)
                {
                    res.push_back(intervals[i]);
                }
                break;
            }
        }
        if (!flag)
        {
            res.push_back(newInterval);
        }

        return res;
    }
};