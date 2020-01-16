/*
 * @Autor: SourDumplings
 * @Date: 2020-01-16 22:21:12
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/3sum-closest
 */

class Solution
{
    public int threeSumClosest(int[] nums, int target)
    {
        Arrays.sort(nums);
        int minD = Integer.MAX_VALUE;
        int res = 0;
        int l = nums.length;
        for (int first = 0; first < l - 2; first++)
        {
            int second = first + 1;
            int third = l - 1;
            while (second < third)
            {
                int sum = nums[first] + nums[second] + nums[third];
                if (Math.abs(sum - target) < minD)
                {
                    minD = Math.abs(sum - target);
                    res = sum;
                }

                if (sum < target)
                {
                    ++second;
                }
                else if (sum > target)
                {
                    --third;
                }
                else
                {
                    return target;
                }
            }
        }
        return res;
    }
}