/*
 * @Author: SourDumplings
 * @Date: 2019-11-03 16:12:27
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/largest-number-at-least-twice-of-others/
 */

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int n = nums.size();
        priority_queue<int> pq(nums.begin(), nums.end());
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[nums[i]] = i;
        }

        int max = pq.top();
        pq.pop();
        int secondMax = 0;
        if (n > 1)
        {
            secondMax = pq.top();
        }
        return max >= secondMax * 2 ? m[max] : -1;
    }
};
