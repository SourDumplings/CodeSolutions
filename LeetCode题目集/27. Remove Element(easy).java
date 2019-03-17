/**
 * @Date    : 2019-01-15 20:15:20
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * https://leetcode.com/problems/remove-element/submissions/
*/

class Solution
{
    public int removeElement(int[] nums, int val)
    {
        if (nums.length == 0)
        {
            return 0;
        }
        int back = nums.length - 1;
        for (int i = 0; i <= back;)
        {
            if (nums[i] == val)
            {
                nums[i] = nums[back];
                --back;
            }
            else
                ++i;
        }
        return back + 1;
    }
}


