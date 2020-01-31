import java.util.HashMap;
import java.util.Map;

/*
 * @Author: SourDumplings
 * @Date: 2019-11-04 17:30:57
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/shortest-completing-word/
 * 
 * 其实对于字母作为键的不要用map，直接用数组比较好
 */

class Solution
{
    public String shortestCompletingWord(String licensePlate, String[] words)
    {
        Map<Character, Integer> map = new HashMap<>();
        int l1 = licensePlate.length();
        int l2 = words.length;
        for (int i = 0; i < l1; i++)
        {
            Character c = licensePlate.charAt(i);
            if (Character.isLetter(c))
            {
                map.merge(Character.toLowerCase(c), 1, Integer::sum);
            }
        }
        int minL = Integer.MAX_VALUE;
        String res = null;
        for (int i = 0; i < l2; i++)
        {
            String word = words[i];
            if (isOK(word, map) && word.length() < minL)
            {
                minL = word.length();
                res = word;
            }
        }
        return res;
    }

    private boolean isOK(final String word, Map<Character, Integer> map)
    {
        Map<Character, Integer> wordMap = new HashMap<>();
        int l = word.length();
        for (int i = 0; i < l; i++)
        {
            wordMap.merge(word.charAt(i), 1, Integer::sum);
        }
        for (Character c : map.keySet())
        {
            if (!wordMap.containsKey(c) || wordMap.get(c) < map.get(c))
            {
                return false;
            }
        }
        return true;
    }
}