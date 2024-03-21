/**
 * @file 274. H-Index(medium)-计数法.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-21
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 引用次数不会超过 n，即论文总数
 * 用一个数组记录引用次数为 i 的论文总数
 * 再从后往前试 n 到 0 即可
 * 
 * 复杂度：时间 O(n) 空间 O(n)
 * 
 * https://leetcode.cn/problems/h-index/solutions/869042/h-zhi-shu-by-leetcode-solution-fnhl/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        int count[n + 1];
        for (int i = 0; i < n + 1; i++)
        {
            count[i] = 0;
        }
        
        for (int i = 0; i < n; i++)
        {
            if (n <= citations[i])
            {
                ++count[n];
            }
            else
            {
                ++count[citations[i]];
            }
        }
        int totalCitation = 0;
        for (int i = n; 0 <= i; --i)
        {
            totalCitation += count[i];
            if (totalCitation >= i)
            {
                return i;
            }
        }
        return 0;
    }
};