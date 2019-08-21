import java.util.Hashtable;
import java.util.Map;

/*
 * @Author: SourDumplings
 * @Date: 2019-08-21 21:31:08
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/contains-duplicate-ii/
 */

class Solution
{
    public boolean containsNearbyDuplicate(int[] nums, int k)
    {
        Map<Integer, Integer> map = new Hashtable<>();
        int n = nums.length;
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            if (map.containsKey(num) && i - map.get(num) <= k)
            {
                return true;
            }
            map.put(num, i);
        }
        return false;
    }
}