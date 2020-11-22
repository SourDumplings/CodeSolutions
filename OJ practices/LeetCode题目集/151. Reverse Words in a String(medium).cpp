/*
 * @Author: SourDumplings
 * @Date: 2020-11-22 22:21:40
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/reverse-words-in-a-string/
 */

class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> S;
        bool flag = false;
        string word;
        for (char c : s)
        {
            if (c != ' ')
            {
                flag = true;
                word += c;
            }
            else if (flag)
            {
                S.push(word);
                flag = false;
                word.clear();
            }
        }
        if (s.back() != ' ')
        {
            S.push(word);
        }
        string res;
        while (!S.empty())
        {
            if (!res.empty())
            {
                res.push_back(' ');
            }
            res += S.top();
            S.pop();
        }
        return res;
    }
};