/*
 * @Author: SourDumplings
 * @Date: 2019-10-14 19:14:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/baseball-game/
 */

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        int l = ops.size();
        stack<int> S;
        int sum = 0;
        for (int i = 0; i < l; i++)
        {
            string &s = ops[i];
            if (s == "+")
            {
                int last1 = S.top();
                S.pop();
                int last2 = S.top();
                S.push(last1);
                S.push(last1 + last2);
                sum += last1 + last2;
            }
            else if (s == "C")
            {
                int last = S.top();
                S.pop();
                sum -= last;
            }
            else if (s == "D")
            {
                int last = S.top();
                S.push(last * 2);
                sum += last * 2;
            }
            else
            {
                int d = stoi(s);
                sum += d;
                S.push(d);
            }
        }
        return sum;
    }
};