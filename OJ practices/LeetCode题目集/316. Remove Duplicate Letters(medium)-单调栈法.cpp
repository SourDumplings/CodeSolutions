/*
 * @Author: SourDumplings
 * @Date: 2021-03-21 10:01:01
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/remove-duplicate-letters/
 */

class Solution
{
public:
    string removeDuplicateLetters(string s)
    {
        stack<char> S;
        int charNum[26];
        bool isInStack[26];
        int l = s.length();
        fill(charNum, charNum + 26, 0);
        fill(isInStack, isInStack + 26, false);
        for (int i = 0; i < l; ++i)
        {
            char c = s[i];
            ++charNum[c - 'a'];
        }
        for (int j = 0; j < l; ++j)
        {
            char c = s[j];
            if (!isInStack[c - 'a'])
            {
                while (!S.empty() && c < S.top() && charNum[S.top() - 'a'] > 0)
                {
                    isInStack[S.top() - 'a'] = false;
                    S.pop();
                }
                S.push(c);
                isInStack[c - 'a'] = true;
            }
            --charNum[c - 'a'];
        }
        string res;
        while (!S.empty())
        {
            res += S.top();
            S.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};