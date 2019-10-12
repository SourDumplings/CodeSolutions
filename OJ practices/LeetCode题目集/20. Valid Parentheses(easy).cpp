/*
 @Date    : 2019-01-07 20:28:19
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/valid-parentheses/
 */

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> S;
        for (char c : s)
        {
            switch (c)
            {
                case '[':
                case '{':
                case '(':
                S.push(c); break;
                case ']':
                {
                    if (!S.empty() && S.top() == '[')
                    {
                        S.pop();
                        break;
                    }
                    else
                        return false;
                }
                case '}':
                {
                    if (!S.empty() && S.top() == '{')
                    {
                        S.pop();
                        break;
                    }
                    else
                        return false;
                }
                case ')':
                {
                    if (!S.empty() && S.top() == '(')
                    {
                        S.pop();
                        break;
                    }
                    else
                        return false;
                }
            }
        }
        if (S.empty())
        {
            return true;
        }
        else
            return false;
    }
};
