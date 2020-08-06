/*
 * @Author: SourDumplings
 * @Date: 2020-08-06 14:29:46
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/subsets/
 */

import java.util.ArrayList;
import java.util.List;

class Solution
{
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> thisSet = new ArrayList<>();

    public List<List<Integer>> subsets(int[] nums)
    {
        int n = nums.length;
        for (int i = 0; i <= n; i++)
        {
            getSubsets(nums, i);
        }
        return res;
    }

    private void getSubsets(int[] nums, int n)
    {
        if (n == 0)
        {
            res.add(new ArrayList<>());
        }
        for (int i = 0; i < nums.length; i++)
        {
            thisSet.add(nums[i]);
            dfs(nums, i, n - 1);
            thisSet.remove(thisSet.size() - 1);
        }
    }

    private void dfs(int[] nums, int i, int k)
    {
        if (k == 0)
        {
            res.add(new ArrayList<>(thisSet));
        }
        else
        {
            for (int j = i + 1; j < nums.length; j++)
            {
                thisSet.add(nums[j]);
                dfs(nums, j, k - 1);
                thisSet.remove(thisSet.size() - 1);
            }
        }
    }
}