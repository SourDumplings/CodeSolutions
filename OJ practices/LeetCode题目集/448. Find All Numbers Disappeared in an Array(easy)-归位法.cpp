/*
 * @Autor: SourDumplings
 * @Date: 2019-09-25 22:18:28
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 * 
 * 该方法的思想是把各个元素放在其改在的位置上，时间复杂度O(n)，空间复杂度O(1)
 */

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            int temp = nums[i];
            if (temp != i + 1 && nums[temp - 1] != temp)
            {
                swap(nums[i], nums[temp - 1]);
                if (nums[i] != i + 1)
                {
                    --i;
                }
            }
        }
        int d = 1;
        vector<int> res;
        for (auto &&i : nums)
        {
            if (i != d)
            {
                res.push_back(d);
            }
            ++d;
        }
        return res;
    }
};