/*
 * @Author: SourDumplings
 * @Date: 2021-01-09 10:06:53
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/summary-ranges/
 */

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        vector<string> res;
        int n = nums.size();
        if (n > 0)
        {
            int i = 0;
            int f, l;
            if (n == 1)
            {
                res.push_back(to_string(nums[0]));
            }
            else
            {
                do
                {
                    f = nums[i];
                    l = f;
                    while (i < n - 1 && l + 1 == nums[i + 1])
                    {
                        ++i;
                        ++l;
                    }
                    if (f == l)
                    {
                        res.push_back(to_string(f));
                    }
                    else
                    {
                        res.push_back(to_string(f) + "->" + to_string(l));
                    }
                    ++i;
                }
                while (i < n);
            }
        }
        return res;
    }
};