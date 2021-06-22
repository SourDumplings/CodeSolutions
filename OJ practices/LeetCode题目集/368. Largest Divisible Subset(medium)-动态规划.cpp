/*
 * @Author: SourDumplings
 * @Date: 2021-06-22 08:25:48
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/largest-divisible-subset/

 参考：https://leetcode-cn.com/problems/largest-divisible-subset/solution/zui-da-zheng-chu-zi-ji-by-leetcode-solut-t4pz/

 扩充整除子集的方法：
 1.新数是子集中最小数的约数
 2.新数是子集中最大数的倍数 

 dp[i] 代表 nums[0:i+1] 最大整除子集中元素的个数
 */

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> res;
        int maxSize = 0;
        int maxVal = 0;
        int n = nums.size();
        int dp[n];
        for (int i = 0; i < n; ++i)
        {
            dp[i] = 1;
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] % nums[j] == 0)
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            if (dp[i] > maxSize)
            {
                maxSize = dp[i];
                maxVal = nums[i];
            }
        }

        // 倒推法得到子集
        if (maxSize == 1)
        {
            res.push_back(nums[0]);
        }
        else
        {
            for (int i = n - 1; i >= 0; --i)
            {
                if (dp[i] == maxSize && maxVal % nums[i] == 0)
                {
                    res.push_back(nums[i]);
                    maxVal = nums[i];
                    --maxSize;
                }
            }
        }
        return res;
    }
};