/**
 * @file 169. Majority Element(easy)-Boyer-Moore 投票算法.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 选出数组中出现次数过半的数
 * @version 1.0.0
 * @date 2024-03-19
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 
 * https://leetcode.cn/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150
 * 
 * 初始化候选者为第一个元素和计数器
 * 遍历，等于候选者则计数器 + 1，否则计数器 - 1
 * 计数器为 0 时改变候选者
 * 最后即可得到结果
 * 
 * 复杂度：空间 O(1) 时间 O(n)
 */

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int res = nums[0];
        int count = 1;
        int n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (count == 0)
            {
                res = nums[i];
            }
            count += res == nums[i] ? 1 : -1;
        }
        return res;
    }
};