/*
 * @Author: SourDumplings
 * @Date: 2021-05-04 09:23:53
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/top-k-frequent-elements/
 */

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
        vector<pair<int, int>> freqV;
        for (auto &p : freqMap)
        {
            freqV.push_back(p);
        }
        sort(freqV.begin(),
             freqV.end(),
             [](const pair<int, int> &p1, const pair<int, int> &p2)
             {
                 return p1.second > p2.second;
             });
        vector<int> res;
        for (int i = 0; i < k; ++i)
        {
            res.push_back(freqV[i].first);
        }
        return res;
    }
};