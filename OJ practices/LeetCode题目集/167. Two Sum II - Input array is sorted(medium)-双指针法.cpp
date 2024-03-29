/**
 * @file 167. Two Sum II - Input array is sorted(medium)-双指针法.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-29
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 双指针法，复杂度：时间 O(n) 空间 O(1)
 * 
 * 假设结果是 numbers[x] + numbers[y] == target
 * 使用双指针 i 和 j 指向头尾
 * 加出来的和 sum 比 target 小就右移 i，比 target 大就左移 j
 * 由于题目保证解存在且唯一，故一定有 i <= x，y <= j
 * 因此这样的双指针法是正确的，不会将解漏掉
 * 
 * https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/solutions/337156/liang-shu-zhi-he-ii-shu-ru-you-xu-shu-zu-by-leet-2/?envType=study-plan-v2&envId=top-interview-150
 * 
 */

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        int i = 0, j = n - 1;
        while (true)
        {
            int sum = numbers[i] + numbers[j];
            if (sum == target)
            {
                return vector<int>({ i + 1, j + 1 });
            }
            else if (sum < target)
            {
                ++i;
            }
            else
            {
                --j;
            }
        }
        return vector<int>(0, 0);
    }
};
