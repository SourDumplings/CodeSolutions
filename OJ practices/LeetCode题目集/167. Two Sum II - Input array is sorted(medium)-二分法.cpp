/**
 * @file 167. Two Sum II - Input array is sorted(medium).cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-29
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 时间复杂度 O(nlogn) 空间 O(1)
 * 
 * https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/?envType=study-plan-v2&envId=top-interview-150
 * 
 */

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        for (int i = 0; i < n; i++)
        {
            int lo = i, hi = n;
            int num1 = numbers[lo];
            while (lo < hi - 1)
            {
                int mi = lo + (hi - lo + 1) / 2;
                int sum = numbers[mi] + num1;
                if (sum == target)
                {
                    return vector<int>({i + 1, mi + 1});
                }

                if (sum < target)
                {
                    lo = mi;
                }
                else
                {
                    hi = mi;
                }
            }
        }
        return vector<int>(0, 0);
    }
};