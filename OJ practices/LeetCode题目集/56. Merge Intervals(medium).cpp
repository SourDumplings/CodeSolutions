/**
 * @file 56. Merge Intervals(medium).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/merge-intervals/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-11
 *
 * @copyright Copyright (c) 2024 SourDumplings
 *
 * 如果我们按照区间的左端点排序，那么在排完序的列表中，可以合并的区间一定是连续的。
 *
 */

class Solution
{
public:
	vector<vector<int>> merge(vector<vector<int>> &intervals)
	{
		sort(
			intervals.begin(),
			intervals.end(),
			[](const vector<int> &lhs, const vector<int> &rhs) { return lhs[0] < rhs[0]; }
		);
		int n = intervals.size();
		vector<vector<int>> res;
		int i = 0;
		while (i < n)
		{
			vector<int> thisInterval{intervals[i][0], intervals[i][1]};
			int thisIntervalRight = intervals[i][1];
			++i;
			while (i < n && intervals[i][0] <= thisIntervalRight)
			{
				thisIntervalRight = max(intervals[i][1], thisIntervalRight);
				++i;
			}
			thisInterval[1] = thisIntervalRight;
			res.push_back(thisInterval);
		}
		return res;
	}
};