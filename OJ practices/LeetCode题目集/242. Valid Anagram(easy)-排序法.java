
/*
 * @Author: SourDumplings
 * @Date: 2019-08-29 13:02:49
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/valid-anagram/
 */

import java.util.Arrays;
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
        if (s.length() != t.length())
        {
            return false;
        }
        char[] c1 = s.toCharArray();
        char[] c2 = t.toCharArray();
        Arrays.sort(c1);
        Arrays.sort(c2);
        int l = c1.length;
        for (int i = 0; i < l; i++)
        {
            if (c1[i] != c2[i])
            {
                return false;
            }
        }
        return true;
    }
}