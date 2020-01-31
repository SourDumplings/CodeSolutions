/*
 * @Author: SourDumplings
 * @Date: 2019-10-11 19:36:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/set-mismatch/
 */

class Solution
{
public:
    vector<int> findErrorNums(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<int> res;
        res.resize(2);
        res[0] = res[1] = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
            {
                if (nums[i] == nums[i - 1])
                {
                    res[0] = nums[i];
                }
                else if (nums[i] > nums[i - 1] + 1)
                {
                    res[1] = nums[i - 1] + 1;
                }
            }
            else if (nums[i] != i + 1)
            {
                res[1] = i + 1;
            }
            if (res[0] != -1 && res[1] != -1)
            {
                break;
            }
        }
        if (nums[n - 1] != n)
        {
            res[1] = n;
        }

        return res;
    }
};