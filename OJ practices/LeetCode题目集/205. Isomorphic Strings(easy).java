import java.util.Hashtable;
import java.util.Map;

/*
 * @Author: SourDumplings
 * @Date: 2019-08-18 10:00:02
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/isomorphic-strings/
 */

class Solution
{
    public boolean isIsomorphic(String s, String t)
    {
        int l = s.length();
        if (l != t.length())
        {
            return false;
        }
        Map<Character, Character> m1 = new Hashtable<>();
        Map<Character, Character> m2 = new Hashtable<>();
        for (int i = 0; i < l; i++)
        {
            Character c1 = s.charAt(i);
            Character c2 = t.charAt(i);
            if (m1.containsKey(c1))
            {
                if (m1.get(c1) != c2)
                {
                    return false;
                }
            }
            else
            {
                if (m2.containsKey(c2))
                {
                    return false;
                }
                m1.put(c1, c2);
                m2.put(c2, c1);
            }
        }
        return true;
    }
}