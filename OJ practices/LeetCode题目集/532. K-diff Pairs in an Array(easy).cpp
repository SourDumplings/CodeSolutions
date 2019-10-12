/*
 * @Autor: SourDumplings
 * @Date: 2019-10-02 08:46:04
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/k-diff-pairs-in-an-array/
 */

class Solution
{
public:
    int findPairs(vector<int> &nums, int k)
    {
        int res = 0;

        if (k == 0)
        {
            sort(nums.begin(), nums.end());
            int n = nums.size();
            for (int i = 0; i < n - 1; i++)
            {
                if (nums[i] == nums[i + 1])
                {
                    ++res;
                    while (i < n - 1 && nums[i + 1] == nums[i])
                    {
                        ++i;
                    }
                }
            }
        }
        else if (k > 0)
        {
            set<int> s;
            for (auto &&i : nums)
            {
                s.insert(i);
            }
            for (auto &&i : s)
            {
                if (s.find(i + k) != s.end())
                {
                    ++res;
                }
            }
        }

        return res;
    }
};