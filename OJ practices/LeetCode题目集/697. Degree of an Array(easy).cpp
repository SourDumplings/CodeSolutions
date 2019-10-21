/*
 * @Autor: SourDumplings
 * @Date: 2019-10-21 16:34:27
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/degree-of-an-array/
 */

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        unordered_map<int, int> freq;
        for (auto &&i : nums)
        {
            ++freq[i];
        }
        int maxF = 0;
        unordered_set<int> maxFSet;
        for (auto &&p : freq)
        {
            if (p.second > maxF)
            {
                maxF = p.second;
                maxFSet.clear();
                maxFSet.insert(p.first);
            }
            else if (p.second == maxF)
            {
                maxFSet.insert(p.first);
            }
        }
        unordered_map<int, int> firstOccur;
        unordered_map<int, int> lastOccur;
        int l = nums.size();
        int res = l;
        for (int i = 0; i < l; i++)
        {
            int num = nums[i];
            if (maxFSet.find(num) != maxFSet.end())
            {
                if (firstOccur.find(num) == firstOccur.end())
                {
                    firstOccur[num] = i;
                }
                lastOccur[num] = i;
            }
        }
        for (auto &&p : firstOccur)
        {
            int num = p.first;
            if (lastOccur[num] - p.second + 1 < res)
            {
                res = lastOccur[num] - p.second + 1;
            }
        }

        return res;
    }
};