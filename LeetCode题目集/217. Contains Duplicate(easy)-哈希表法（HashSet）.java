import java.util.Set;

/*
 * @Author: SourDumplings
 * @Date: 2019-08-20 20:55:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/contains-duplicate/
 */

class Solution
{
    public boolean containsDuplicate(int[] nums)
    {
        Set<Integer> set = new HashSet<>();
        for (int i : nums)
        {
            if (set.contains(i))
            {
                return true;
            }
            set.add(i);
        }
        return false;
    }
}