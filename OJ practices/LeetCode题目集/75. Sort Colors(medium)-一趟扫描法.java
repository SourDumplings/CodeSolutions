/*
 * @Author: SourDumplings
 * @Date: 2020-08-04 10:34:10
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/sort-colors/
 */ 

class Solution
{
    public void sortColors(int[] nums)
    {
        int p0 = 0;
        int p2 = nums.length - 1;
        int curr = 0;
        while (curr <= p2)
        {
            int temp = nums[curr];
            if (temp == 0)
            {
                nums[curr] = nums[p0];
                nums[p0] = temp;
                ++p0;
                ++curr;
            }
            else if (temp == 2)
            {
                nums[curr] = nums[p2];
                nums[p2] = temp;
                --p2;
            }
            else
            {
                ++curr;
            }
        }
    }
}