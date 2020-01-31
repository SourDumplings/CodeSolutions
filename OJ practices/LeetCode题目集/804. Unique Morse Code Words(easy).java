import java.util.HashSet;
import java.util.Set;

/*
 * @Author: SourDumplings
 * @Date: 2019-11-19 19:03:16
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/unique-morse-code-words/
 */

class Solution
{
    public int uniqueMorseRepresentations(String[] words)
    {
        String[] mores =
        { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---",
                ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
        Set<String> set = new HashSet<>();
        for (String word : words)
        {
            int l = word.length();
            StringBuilder sb = new StringBuilder();
            for (int i = 0; i < l; i++)
            {
                char c = word.charAt(i);
                sb.append(mores[c - 'a']);
            }
            set.add(sb.toString());
        }
        return set.size();
    }
}