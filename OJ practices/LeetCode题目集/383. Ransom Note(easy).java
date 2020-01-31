import java.util.Hashtable;
import java.util.Map;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-18 22:16:52
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/ransom-note/
 */

class Solution
{
    public boolean canConstruct(String ransomNote, String magazine)
    {
        Map<Character, Integer> map = new Hashtable<>();
        int l1 = ransomNote.length();
        int l2 = magazine.length();
        for (int i = 0; i < l2; i++)
        {
            char c = magazine.charAt(i);
            if (map.containsKey(c))
            {
                map.put(c, map.get(c) + 1);
            }
            else
            {
                map.put(c, 1);
            }
        }
        for (int i = 0; i < l1; i++)
        {
            char c = ransomNote.charAt(i);
            if (!map.containsKey(c) || map.get(c) == 0)
            {
                return false;
            }
            else
            {
                map.put(c, map.get(c) - 1);
            }
        }
        return true;
    }
}