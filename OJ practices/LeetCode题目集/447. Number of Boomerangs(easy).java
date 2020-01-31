import java.util.Hashtable;
import java.util.Map;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-25 21:54:35
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/number-of-boomerangs/
 */

class Solution
{
    public int numberOfBoomerangs(int[][] points)
    {
        int res = 0;
        int n = points.length;
        for (int i = 0; i < n; i++)
        {
            Map<Integer, Integer> m = new Hashtable<>();
            for (int j = 0; j < n; j++)
            {
                int d = (points[i][1] - points[j][1]) * (points[i][1] - points[j][1])
                        + (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]);
                if (m.containsKey(d))
                {
                    m.put(d, m.get(d) + 1);
                }
                else
                {
                    m.put(d, 1);
                }
            }
            for (int k : m.keySet())
            {
                int num = m.get(k);
                if (k != 0 && num >= 2)
                {
                    res += num * (num - 1); // A(2, num)
                }
            }
        }
        return res;
    }
}
