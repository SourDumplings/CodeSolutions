/*
 * @Author: SourDumplings
 * @Date: 2021-05-04 10:22:25
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/top-k-frequent-elements/
 */

class cmp
{
public:
    bool operator()(const pair<int, int> &p1, const pair<int, int> &p2)
    {
        return p1.second < p2.second;
    }
};

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> freqMap;
        for (int num : nums)
        {
            if (freqMap.find(num) == freqMap.end())
            {
                freqMap[num] = 1;
            }
            else
            {
                ++freqMap[num];
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pQ;
        for (auto &p : freqMap)
        {
            pQ.push(p);
        }
        vector<int> res;
        for (int i = 0; i < k; ++i)
        {
            res.push_back(pQ.top().first);
            pQ.pop();
        }
        return res;
    }
};