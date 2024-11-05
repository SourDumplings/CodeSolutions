/**
 * @brief https://leetcode.cn/problems/summary-ranges/?envType=study-plan-v2&envId=top-interview-150
 * 
 */

class Solution
{
public:
	vector<string> summaryRanges(vector<int> &nums)
	{
		vector<string> res;
		if (nums.empty()) { return res; }

		size_t i = 0, j = 0;
		size_t n = nums.size();
		while (i < n)
		{
			string str = to_string(nums[i]);
			while (j < n - 1 && nums[j + 1] == nums[j] + 1)
			{
				++j;
			}
			if (i < j) { str += "->" + to_string(nums[j]); }
			++j;
			i = j;
			res.push_back(str);
		}
		return res;
	}
};