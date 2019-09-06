import java.util.Hashtable;
import java.util.Map;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-06 10:46:09
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/word-pattern/
 */

class Solution
{
    public boolean wordPattern(String pattern, String str)
    {
        Map<Character, String> m1 = new Hashtable<>();
        Map<String, Character> m2 = new Hashtable<>();
        String[] sA = str.split(" ");
        int l = pattern.length();
        if (l != sA.length)
        {
            return false;
        }
        for (int i = 0; i < l; i++)
        {
            String s = sA[i];
            Character c = pattern.charAt(i);
            if (!m1.containsKey(c))
            {
                if (!m2.containsKey(s))
                {
                    m1.put(c, s);
                    m2.put(s, c);
                }
                else
                {
                    return false;
                }
            }
            else if (!m1.get(c).equals(s))
            {
                return false;
            }
        }
        return true;
    }
}