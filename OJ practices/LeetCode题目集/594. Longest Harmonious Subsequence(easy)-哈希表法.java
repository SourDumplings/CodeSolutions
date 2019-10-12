import java.util.Hashtable;
import java.util.Map;

/*
 * @Autor: SourDumplings
 * @Date: 2019-10-07 22:51:59
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-harmonious-subsequence/
 */

class Solution
{
    public int findLHS(int[] nums)
    {
        Map<Integer, Integer> map = new Hashtable<>();
        for (int i : nums)
        {
            if (map.containsKey(i))
            {
                map.put(i, map.get(i) + 1);
            }
            else
            {
                map.put(i, 1);
            }
        }
        int res = 0;
        for (int i : map.keySet())
        {
            if (map.containsKey(i + 1) && map.get(i + 1) + map.get(i) > res)
            {
                res = map.get(i + 1) + map.get(i);
            }
        }
        return res;
    }
}