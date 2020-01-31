import java.util.Arrays;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-20 08:45:12
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/find-the-difference/
 */

class Solution
{
    public char findTheDifference(String s, String t)
    {
        int[] hashTable = new int[26];
        int ls = s.length();
        int lt = t.length();
        Arrays.fill(hashTable, 0);
        for (int i = 0; i < ls; i++)
        {
            char c = s.charAt(i);
            ++hashTable[c - 'a'];
        }
        for (int i = 0; i < lt; i++)
        {
            char c = t.charAt(i);
            int j = c - 'a';
            if (hashTable[j] == 0)
            {
                return c;
            }
            else
            {
                --hashTable[j];
            }
        }
        return ' ';
    }
}