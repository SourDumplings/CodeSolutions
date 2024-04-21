/**
 * @file 1. Two Sum(easy)-单趟扫描哈希表法.cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-04-21
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/two-sum/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> posMap;
        int n = nums.size();
        vector<int> ret(2);
        for (int i = 0; i < n; i++)
        {
            ret[0] = i;
            int res = target - nums[i];
            auto it = posMap.find(res);
            if (it != posMap.end())
            {
                ret[1] = it->second;
                break;
            }
            
            posMap[nums[i]] = i;
        }
        return ret;
    }
};
