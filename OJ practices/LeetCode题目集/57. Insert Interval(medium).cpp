/**
 * @file 57. Insert Interval(hard).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief https://leetcode.cn/problems/insert-interval/description/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-12
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 在给定的区间集合 X 互不重叠的前提下，当我们需要插入一个新的区间 S=[left,right] 时，我们只需要：
 * 1. 找出所有与区间 S 重叠的区间集合 X'
 * 2. 将 X' 中的所有区间连带上区间 S 合并成一个大区间
 * 3. 最终的答案即为不与 X' 重叠的区间以及合并后的大区间
 */

class Solution
{
public:
	vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
	{
		bool isOverlapPlaced = false;
		int i				 = 0;
		int n				 = intervals.size();
		vector<vector<int>> res;
		vector<int> overlapInterval(newInterval);
		while (i < n)
		{
			const vector<int>& interval = intervals[i];
			if (interval[1] < newInterval[0]) { res.emplace_back(interval); }
			else if (newInterval[1] < interval[0])
			{
				if (!isOverlapPlaced)
				{
					res.emplace_back(overlapInterval);
					isOverlapPlaced = true;
				}
				res.emplace_back(interval);
			}
			else
			{
				overlapInterval[0] = min(overlapInterval[0], interval[0]);
				overlapInterval[1] = max(overlapInterval[1], interval[1]);
			}
			++i;
		}
		if (!isOverlapPlaced)
		{
			res.emplace_back(overlapInterval);
			isOverlapPlaced = true;
		}
		return res;
	}
};