/**
 * @Date    : 2019-01-07 20:35:41
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * https://leetcode.com/problems/valid-parentheses/
*/

class Solution
{
    public boolean isValid(String s)
    {
        Stack<Character> S = new Stack<Character>();
        for (int i = 0; i != s.length(); ++i)
        {
            Character c = new Character(s.charAt(i));
            if (c == '(' || c == '[' || c == '{')
            {
                S.push(c);
            }
            else if (c == ')')
            {
                if (!S.empty() && S.peek() == '(')
                {
                    S.pop();
                }
                else
                    return false;
            }
            else if (c == ']')
            {
                if (!S.empty() && S.peek() == '[')
                {
                    S.pop();
                }
                else
                    return false;
            }
            else if (c == '}')
            {
                if (!S.empty() && S.peek() == '{')
                {
                    S.pop();
                }
                else
                    return false;
            }
        }
        if (S.empty())
        {
            return true;
        }
        else
            return false;
    }
}

