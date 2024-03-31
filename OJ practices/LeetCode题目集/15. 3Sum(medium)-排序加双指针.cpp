/**
 * @file 15. 3Sum(medium).cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-31
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 排序加双指针，复杂度：时间 O(n^2) 空间不计算返回数组 O(1)
 * https://leetcode.cn/problems/3sum/solutions/284681/san-shu-zhi-he-by-leetcode-solution/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
        {
            int f = nums[i];
            if (0 < i && f == nums[i - 1])
            {
                continue;
            }

            int l = i + 1;
            int r = n - 1;
            while (l < r)
            {
                while (l < r && f + nums[l] + nums[r] < 0)
                    ++l;
                while (l < r && 0 < f + nums[l] + nums[r])
                    --r;
                if (l == r)
                {
                    break;
                }

                if (f + nums[l] + nums[r] == 0)
                {
                    res.emplace_back(vector<int>({ f, nums[l], nums[r] }));
                    do
                    {
                        ++l;
                    } while (l < r && nums[l] == nums[l - 1]);
                    do
                    {
                        --r;
                    } while (l < r && nums[r] == nums[r + 1]);
                }
            }

        }

        return res;
    }
};