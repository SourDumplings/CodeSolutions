import java.util.Hashtable;
import java.util.Map;
import java.util.Vector;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-14 10:23:05
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/intersection-of-two-arrays-ii/
 */

class Solution
{
    public int[] intersect(int[] nums1, int[] nums2)
    {
        Map<Integer, Integer> map1 = new Hashtable<>();
        Map<Integer, Integer> map2 = new Hashtable<>();
        for (int i : nums1)
        {
            if (map1.containsKey(i))
            {
                map1.replace(i, map1.get(i) + 1);
            }
            else
            {
                map1.put(i, 1);
            }
        }
        for (int i : nums2)
        {
            if (map2.containsKey(i))
            {
                map2.replace(i, map2.get(i) + 1);
            }
            else
            {
                map2.put(i, 1);
            }
        }
        Vector<Integer> temp = new Vector<>();
        for (int i : map1.keySet())
        {
            if (map2.containsKey(i))
            {
                int n1 = map1.get(i);
                int n2 = map2.get(i);
                int n = n1 < n2 ? n1 : n2;
                while (n-- > 0)
                {
                    temp.add(i);
                }
            }
        }
        int n = temp.size();
        int[] res = new int[n];
        int i = 0;
        for (int num : temp)
        {
            res[i++] = num;
        }
        return res;
    }
}