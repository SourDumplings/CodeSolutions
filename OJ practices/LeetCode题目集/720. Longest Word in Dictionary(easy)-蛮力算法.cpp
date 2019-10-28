/*
 * @Autor: SourDumplings
 * @Date: 2019-10-28 14:24:25
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-word-in-dictionary/
 */

class Solution
{
public:
    string longestWord(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string &s1, const string &s2) {
            if (s1.length() == s2.length())
            {
                return s1 < s2;
            }
            else
            {
                return s1.length() > s2.length();
            }
        });
        set<string> wordSet(words.begin(), words.end());
        for (auto &&word : words)
        {
            int l = word.length();
            bool flag = true;
            for (int i = 1; i <= l; i++)
            {
                if (wordSet.find(word.substr(0, i)) == wordSet.end())
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
};