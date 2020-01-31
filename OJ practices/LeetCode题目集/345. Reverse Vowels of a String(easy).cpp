/*
 * @Author: SourDumplings
 * @Date: 2019-09-12 23:48:51
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/reverse-vowels-of-a-string/
 */

class Solution
{
public:
    string reverseVowels(string s)
    {
        set<char> vowels({'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'});
        int l = s.length();
        int i = 0, j = l - 1;
        while (i < j)
        {
            while (i < j && vowels.find(s[i]) == vowels.end())
                ++i;
            while (i < j && vowels.find(s[j]) == vowels.end())
                --j;
            if (i < j)
            {
                swap(s[i], s[j]);
                ++i;
                --j;
            }
        }
        return s;
    }
};