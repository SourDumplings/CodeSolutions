/*
 * @Author: SourDumplings
 * @Date: 2020-11-21 21:45:33
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
 */

class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> S;
        int size = tokens.size();
        for (int i = 0; i < size; ++i)
        {
            string &s = tokens[i];
            if (isdigit(s.back()))
            {
                S.push(stoi(s));
            }
            else
            {
                int d2 = S.top();
                S.pop();
                int d1 = S.top();
                S.pop();
                int res;
                switch (s[0])
                {
                    case '+':
                    {
                        res = d1 + d2;
                        break;
                    }
                    case '-':
                    {
                        res = d1 - d2;
                        break;
                    }
                    case '*':
                    {
                        res = d1 * d2;
                        break;
                    }
                    case '/':
                    {
                        res = d1 / d2;
                        break;
                    }
                }
                S.push(res);
            }
        }
        return S.top();
    }
};