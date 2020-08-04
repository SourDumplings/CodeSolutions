/*
 * @Author: SourDumplings
 * @Date: 2020-08-04 09:55:48
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/sort-colors/
 */ 

class Solution
{
    public void sortColors(int[] nums)
    {
        int numOfZeros = 0;
        int numOfOnes = 0;
        for (int i = 0; i < nums.length; i++)
        {
            if (nums[i] == 0)
            {
                ++numOfZeros;
            }
            else if (nums[i] == 1)
            {
                ++numOfOnes;
            }
        }
        for (int i = 0; i < nums.length; i++)
        {
            if (i < numOfZeros)
            {
                nums[i] = 0;
            }
            else if (i < numOfOnes + numOfZeros)
            {
                nums[i] = 1;
            }
            else
            {
                nums[i] = 2;
            }
        }
    }
}