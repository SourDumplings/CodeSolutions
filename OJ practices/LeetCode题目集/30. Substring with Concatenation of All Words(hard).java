import java.util.HashMap;
import java.util.List;
import java.util.Map;

/*
 * @Author: SourDumplings
 * @Date: 2020-01-29 12:08:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/substring-with-concatenation-of-all-words/
 */

class Solution
{
    public List<Integer> findSubstring(String s, String[] words)
    {
        List<Integer> res = new ArrayList<>();
        if (words.length == 0)
        {
            return res;
        }

        Map<String, Integer> map = new HashMap<>();
        int lOfWord = words[0].length();
        int lOfSubString = 0;
        for (String word : words)
        {
            map.put(word, map.getOrDefault(word, 0) + 1);
            lOfSubString += lOfWord;
        }
        int l = s.length();
        for (int i = 0; i <= l - lOfSubString; i++)
        {
            String subString = s.substring(i, i + lOfSubString);
            Map<String, Integer> temp = (Map<String, Integer>) ((HashMap) map).clone();
            boolean flag = true;
            for (int j = 0; j <= lOfSubString - lOfWord; j += lOfWord)
            {
                String word = subString.substring(j, j + lOfWord);
                if (!temp.containsKey(word) || temp.get(word) == 0)
                {
                    flag = false;
                    break;
                }
                else
                {
                    temp.put(word, temp.get(word) - 1);
                }
            }
            if (flag)
            {
                res.add(i);
            }
        }
        return res;
    }
}