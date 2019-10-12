import java.util.Hashtable;
import java.util.Map;

/*
 * @Author: SourDumplings
 * @Date: 2019-08-29 12:56:03
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/valid-anagram/
 */

class Solution
{
    public boolean isAnagram(String s, String t)
    {
        Map<Character, Integer> m1 = new Hashtable<>();
        Map<Character, Integer> m2 = new Hashtable<>();
        int l1 = s.length();
        int l2 = t.length();
        for (int i = 0; i < l1; i++)
        {
            Character c = s.charAt(i);
            if (!m1.containsKey(c))
            {
                m1.put(c, 1);
            }
            else
            {
                m1.put(c, 1 + m1.get(c));
            }
        }
        for (int i = 0; i < l2; i++)
        {
            Character c = t.charAt(i);
            if (!m2.containsKey(c))
            {
                m2.put(c, 1);
            }
            else
            {
                m2.put(c, 1 + m2.get(c));
            }
        }
        return m1.equals(m2);
    }
}