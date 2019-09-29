/*
 * @Autor: SourDumplings
 * @Date: 2019-09-29 17:34:39
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/detect-capital/
 */

class Solution
{
public:
    bool detectCapitalUse(string word)
    {
        bool firstCap = isupper(word[0]);
        int l = word.length();
        if (l < 2)
        {
            return true;
        }
        if (firstCap)
        {
            bool allCap = isupper(word[1]);
            for (int i = 2; i < l; i++)
            {
                char c = word[i];
                if (allCap && islower(c) || !allCap && isupper(c))
                {
                    return false;
                }
            }
        }
        else
        {
            for (int i = 1; i < l; i++)
            {
                if (isupper(word[i]))
                {
                    return false;
                }
            }
        }
        return true;
    }
};