import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

/*
 * @Autor: SourDumplings
 * @Date: 2019-10-02 08:58:38
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/k-diff-pairs-in-an-array/
 */

class Solution
{
    public int findPairs(int[] nums, int k)
    {
        int res = 0;
        if (k == 0)
        {
            Arrays.sort(nums);
            int l = nums.length;
            for (int i = 0; i < l - 1; i++)
            {
                if (nums[i] == nums[i + 1])
                {
                    ++res;
                    while (i < l - 1 && nums[i] == nums[i + 1])
                    {
                        ++i;
                    }
                }
            }
        }
        else if (k > 0)
        {
            Set<Integer> set = new HashSet<>();
            for (int i : nums)
            {
                set.add(i);
            }
            for (int i : set)
            {
                if (set.contains(i + k))
                {
                    ++res;
                }
            }
        }
        return res;
    }
}