/*
 * @Author: SourDumplings
 * @Date: 2019-10-04 15:17:51
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/reverse-words-in-a-string-iii/
 */

class Solution
{
public:
    string reverseWords(string s)
    {
        istringstream sin(s);
        string word;
        string res;
        int output = 0;
        while (sin >> word)
        {
            if (output++)
            {
                res += ' ';
            }

            reverse(word.begin(), word.end());
            res += word;
        }
        return res;
    }
};