import java.util.Collections;
import java.util.HashMap;
import java.util.Map;

/*
 * @Autor: SourDumplings
 * @Date: 2019-10-21 16:58:10
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/degree-of-an-array/
 */

class Solution
{
    public int findShortestSubArray(int[] nums)
    {
        Map<Integer, Integer> count = new HashMap<>();
        Map<Integer, Integer> left = new HashMap<>();
        Map<Integer, Integer> right = new HashMap<>();
        int l = nums.length;
        for (int i = 0; i < l; i++)
        {
            int num = nums[i];
            left.putIfAbsent(num, i);
            count.merge(num, 1, Integer::sum);
            right.put(num, i);
        }
        int maxF = Collections.max(count.values());
        int res = l;
        for (int num : left.keySet())
        {
            if (count.get(num) == maxF)
            {
                int r = right.get(num);
                int le = left.get(num);
                if (r - le + 1 < res)
                {
                    res = r - le + 1;
                }
            }
        }
        return res;
    }
}