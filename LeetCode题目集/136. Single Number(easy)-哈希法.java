
/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/single-number/
 * @Date: 2019-03-31 19:18:33
 */

import java.util.Hashtable;

class Solution
{
    public int singleNumber(int[] nums)
    {
        Hashtable<Integer, Integer> h = new Hashtable<Integer, Integer>();
        for (int i : nums)
        {
            if (h.containsKey(i))
                h.put(i, h.get(i) + 1);
            else
                h.put(i, 1);
        }
        int ret = 0;
        for (int i : nums)
        {
            if (h.get(i) == 1)
            {
                ret = i;
                break;
            }
        }
        return ret;
    }
}