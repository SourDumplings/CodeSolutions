import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @Author: SourDumplings
 * @Date: 2020-01-14 20:29:47
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/3sum/
 */

class Solution
{
    public List<List<Integer>> threeSum(int[] nums)
    {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        Arrays.sort(nums);
        int l = nums.length;
        boolean first1 = true, first2 = true;
        int last1 = 0, last2 = 0;
        for (int i = 0; i < l; i++)
        {
            if (!first1 && nums[i] == last1)
            {
                first1 = false;
                continue;
            }
            for (int j = i + 1; j < l; j++)
            {
                if (!first2 && nums[j] == last2)
                {
                    first2 = false;
                    continue;
                }
                int d = 0 - nums[i] - nums[j];
                int k = Arrays.binarySearch(nums, j + 1, l, d);
                if (k >= 0)
                {
                    List<Integer> triple = new ArrayList<>();
                    triple.add(nums[i]);
                    triple.add(nums[j]);
                    triple.add(nums[k]);
                    res.add(triple);
                }
                first2 = false;
                last2 = nums[j];
            }
            first1 = false;
            last1 = nums[i];
        }
        return res;
    }
}