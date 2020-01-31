import java.util.ArrayList;
import java.util.Hashtable;
import java.util.List;
import java.util.Map;

/*
 * @Author: SourDumplings
 * @Date: 2019-10-09 16:34:13
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/minimum-index-sum-of-two-lists/
 */

class Solution
{
    public String[] findRestaurant(String[] list1, String[] list2)
    {
        Map<String, Integer> map = new Hashtable<>();
        int l1 = list1.length;
        int l2 = list2.length;
        for (int i = 0; i < l1; i++)
        {
            map.put(list1[i], i);
        }
        int minI = Integer.MAX_VALUE;
        List<String> res = new ArrayList<>();
        for (int i = 0; i < l2; i++)
        {
            String s = list2[i];
            if (map.containsKey(s))
            {
                int i1 = map.get(s);
                if (i1 + i < minI)
                {
                    res.clear();
                    res.add(s);
                    minI = i1 + i;
                }
                else if (i1 + i == minI)
                {
                    res.add(s);
                }
            }
        }
        int l = res.size();
        String[] realRes = new String[l];
        res.toArray(realRes);
        return realRes;
    }
}