import java.util.HashSet;
import java.util.Set;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-13 23:16:11
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/intersection-of-two-arrays/
 */

class Solution
{
    public int[] intersection(int[] nums1, int[] nums2)
    {
        Set<Integer> s1 = new HashSet<>();
        Set<Integer> s2 = new HashSet<>();
        for (int i : nums1)
        {
            s1.add(i);
        }
        for (int i : nums2)
        {
            s2.add(i);
        }
        s1.retainAll(s2);
        int n = s1.size();
        int[] res = new int[n];
        int j = 0;
        for (int i : s1)
        {
            res[j++] = i;
        }
        return res;
    }
}