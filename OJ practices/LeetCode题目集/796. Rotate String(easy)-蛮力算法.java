import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;

/*
 * @Autor: SourDumplings
 * @Date: 2019-11-15 08:11:00
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/rotate-string/
 */

class Solution
{
    public boolean rotateString(String A, String B)
    {
        if (A.length() == 0 && B.length() == 0)
        {
            return true;
        }

        char[] chars = A.toCharArray();
        List<Character> listA = new LinkedList<>();
        for (Character c : chars)
        {
            listA.add(c);
        }
        int l = chars.length;
        List<Character> listB = new LinkedList<>();

        char[] charsB = B.toCharArray();
        for (char c : charsB)
        {
            listB.add(c);
        }
        for (int i = 0; i < l; i++)
        {
            if (listA.equals(listB))
            {
                return true;
            }
            listA.add(0, listA.remove(l - 1));
        }
        return false;
    }
}