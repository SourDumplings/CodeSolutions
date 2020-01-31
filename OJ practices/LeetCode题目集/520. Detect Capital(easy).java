/*
 * @Author: SourDumplings
 * @Date: 2019-09-29 17:46:01
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/detect-capital/
 */

class Solution
{
    public boolean detectCapitalUse(String word)
    {
        char firstC = word.charAt(0);
        boolean firstCap = firstC <= 'Z' && firstC >= 'A';
        int l = word.length();
        if (l < 2)
        {
            return true;
        }
        if (firstCap)
        {
            char secondC = word.charAt(1);
            boolean secondCap = secondC <= 'Z' && secondC >= 'A';
            for (int i = 2; i < l; i++)
            {
                char c = word.charAt(i);
                if (secondCap && c <= 'z' && c >= 'a' || !secondCap && c <= 'Z' && c >= 'A')
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = 1; i < l; i++)
            {
                char c = word.charAt(i);
                if (c >= 'A' && c <= 'Z')
                {
                    return false;
                }
            }
        }
        return true;
    }
}