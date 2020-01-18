import java.util.ArrayList;
import java.util.List;

/*
 * @Autor: SourDumplings
 * @Date: 2020-01-18 10:17:56
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/4sum/
 * 
 * 通过把 KSum 降低为 K-1 Sum，然后逐步降低，最后双指针法处理 2Sum
 */

class Solution
{
    public List<List<Integer>> fourSum(int[] nums, int target)
    {
        Arrays.sort(nums);
        List<Integer> thisTuple = new ArrayList<>();
        List<List<Integer>> res = new ArrayList<>();
        kSum(nums, target, thisTuple, 4, 0, nums.length - 3, res);
        return res;
    }

    private void kSum(int[] nums, int target, List<Integer> thisTuple, int k, int b, int e, List<List<Integer>> res)
    {
        if (k > 2)
        {
            for (int i = b; i < e; i++)
            {
                if (i != b && nums[i - 1] == nums[i])
                {
                    continue;
                }
                thisTuple.add(nums[i]);
                kSum(nums, target - nums[i], thisTuple, k - 1, i + 1, e + 1, res);
                thisTuple.remove(thisTuple.size() - 1);
            }
        }
        else if (k == 2)
        {
            int left = b, right = e;
            while (left < right)
            {
                int sum = nums[left] + nums[right];
                if (sum == target)
                {
                    List<Integer> temp = new ArrayList<>(thisTuple);
                    temp.add(nums[left]);
                    temp.add(nums[right]);
                    res.add(new ArrayList<>(temp));
                    while (left < right && nums[left] == nums[left + 1])
                    {
                        ++left;
                    }
                    while (left < right && nums[right] == nums[right - 1])
                    {
                        --right;
                    }
                    ++left;
                    --right;
                }
                else if (sum < target)
                {
                    ++left;
                }
                else
                {
                    --right;
                }
            }
        }
    }
}