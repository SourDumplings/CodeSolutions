/**
 * @file 452. Minimum Number of Arrows to Burst Balloons(medium).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/minimum-number-of-arrows-to-burst-balloons/description/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-12
 *
 * @copyright Copyright (c) 2024 SourDumplings
 *
 */

class Solution
{
public:
	int findMinArrowShots(vector<vector<int>> &points)
	{
		sort(
			points.begin(),
			points.end(),
			[](const vector<int> &p1, const vector<int> &p2) { return p1[0] < p2[0]; }
		);
		int n	= points.size();
		int r	= points[0][1];
		int i	= 0;
		int res = 0;
		while (i < n)
		{
			if (i < n)
			{
				r = points[i][1];
				++i;
				++res;
			}
			while (i < n && points[i][0] <= r)
			{
				r = min(points[i][1], r);
				++i;
			}
		}
		return res;
	}
};