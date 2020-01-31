import java.util.Arrays;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-19 09:09:24
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/first-unique-character-in-a-string/
 */

class Solution
{
    public int firstUniqChar(String s)
    {
        int[] hashTable = new int[26];
        Arrays.fill(hashTable, 0);
        int l = s.length();
        for (int i = 0; i < l; i++)
        {
            char c = s.charAt(i);
            ++hashTable[c - 'a'];
        }
        for (int i = 0; i < l; i++)
        {
            char c = s.charAt(i);
            if (hashTable[c - 'a'] == 1)
            {
                return i;
            }
        }
        return -1;
    }
}