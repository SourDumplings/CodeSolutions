/*
 * @Autor: SourDumplings
 * @Date: 2020-01-23 16:32:04
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/generate-parentheses
 * 
 * 对于任何一个有效的括号序列，第一位一定是左括号，最后一位一定是右括号
 * 因此将括号序列拆成两子列，遍历两个子列的长度，进行递归即可
 */

class Solution
{
private:
    unordered_map<int, vector<string>> m;

public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> res;
        if (n == 0)
        {
            res.push_back("");
        }

        for (int i = 0; i < n; i++)
        {
            vector<string> &leftRes = getOrSetDefault(i);
            for (auto &&left : leftRes)
            {
                vector<string> &rightRes = getOrSetDefault(n - i - 1);
                for (auto &&right : rightRes)
                {
                    res.push_back("(" + left + ")" + right);
                }
            }
        }
        return res;
    }

    vector<string> &getOrSetDefault(int num)
    {
        if (m.find(num) == m.end())
        {
            m[num] = generateParenthesis(num);
        }
        return m[num];
    }
};