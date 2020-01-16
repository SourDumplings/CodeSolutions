/*
 * @Autor: SourDumplings
 * @Date: 2020-01-16 21:19:55
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/3sum-closest/
 */

class Solution
{
    public int threeSumClosest(int[] nums, int target)
    {
        Arrays.sort(nums);
        int minD = Integer.MAX_VALUE;
        int res = 0;
        int l = nums.length;
        boolean allNeg = true;
        for (int i = 0; i < l - 2; i++)
        {
            for (int j = i + 1; j < l - 1; j++)
            {
                int sum, lastSum = Integer.MAX_VALUE;
                for (int k = j + 1; k < l; k++)
                {
                    sum = nums[i] + nums[j] + nums[k];
                    if (sum == target)
                    {
                        return target;
                    }
                    else if (sum > target)
                    {
                        allNeg = false;
                        if (k != j + 1)
                        {
                            if (target - lastSum < minD)
                            {
                                minD = target - lastSum;
                                res = lastSum;
                            }
                        }
                        if (sum - target < minD)
                        {
                            minD = target - sum;
                            res = sum;
                        }
                        break;
                    }
                    lastSum = sum;
                }
                if (allNeg && lastSum < target)
                {
                    res = lastSum;
                    minD = target - lastSum;
                }
            }
        }
        return res;
    }
}