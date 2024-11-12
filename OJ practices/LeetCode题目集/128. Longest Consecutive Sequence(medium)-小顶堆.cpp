/**
 * @file 128. Longest Consecutive Sequence(medium)-小顶堆.cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief
 * https://leetcode.cn/problems/longest-consecutive-sequence/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-11
 *
 * @copyright Copyright (c) 2024 SourDumplings
 *
 */

class Solution
{
public:
	int longestConsecutive(vector<int> &nums)
	{
		priority_queue<int, vector<int>, greater<int>> q;
		std::for_each(nums.begin(), nums.end(), [&q](int num) { q.push(num); });
		int lastNum	   = INT32_MIN;
		int thisLength = 0;
		int maxLength  = 0;
		while (!q.empty())
		{
			while (!q.empty() && q.top() == lastNum)
				q.pop();
			if (q.empty()) { break; }
			int num = q.top();
			q.pop();
			if (lastNum + 1 == num) { ++thisLength; }
			else
			{
				if (maxLength < thisLength) { maxLength = thisLength; }
				thisLength = 1;
			}
			lastNum = num;
		}
		if (maxLength < thisLength) { maxLength = thisLength; }

		return maxLength;
	}
};