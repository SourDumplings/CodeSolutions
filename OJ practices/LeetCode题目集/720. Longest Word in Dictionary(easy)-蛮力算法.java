import java.util.Arrays;
import java.util.HashSet;

/*
 * @Author: SourDumplings
 * @Date: 2019-10-28 14:40:41
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-word-in-dictionary/
 */

class Solution
{
    public String longestWord(String[] words)
    {
        Set<String> wordSet = new HashSet<>();
        for (String word : words)
        {
            wordSet.add(word);
        }
        Arrays.sort(words, (s1, s2) ->
        {
            if (s1.length() == s2.length())
            {
                return s1.compareTo(s2);
            }
            else
            {
                return s2.length() - s1.length();
            }
        });
        for (String word : words)
        {
            int l = word.length();
            boolean flag = true;
            for (int i = 1; i <= l; i++)
            {
                if (!wordSet.contains(word.substring(0, i)))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                return word;
            }
        }
        return "";
    }
}