/*
 * @Author: SourDumplings
 * @Date: 2021-01-15 11:07:38
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/different-ways-to-add-parentheses/
 * 
 * 参考：https://leetcode-cn.com/problems/different-ways-to-add-parentheses/solution/pythongolang-fen-zhi-suan-fa-by-jalan/
 */

class Solution
{
private:
    vector<int> do_compute(const string &input, int b, int e)
    {
        bool isDigit = true;
        for (int i = b; i < e; ++i)
        {
            char c = input[i];
            if (!isdigit(c))
            {
                isDigit = false;
                break;
            }
        }

        vector<int> res;
        if (isDigit)
        {
            res.push_back(stoi(input.substr(b, e - b)));
            return res;
        }

        for (int i = b; i < e; ++i)
        {
            char c = input[i];
            if (isOp(c))
            {
                vector<int> left = do_compute(input, b, i);
                vector<int> right = do_compute(input, i + 1, e);

                for (int l : left)
                {
                    for (int r : right)
                    {
                        switch (c)
                        {
                            case '+':
                            {
                                res.push_back(l + r);
                                break;
                            }
                            case '-':
                            {
                                res.push_back(l - r);
                                break;
                            }
                            case '*':
                            {
                                res.push_back(l * r);
                                break;
                            }
                        }
                    }
                }
            }
        }
        return res;
    }

    bool isOp(char c)
    {
        return c == '+' || c == '-' || c == '*';
    }
public:
    vector<int> diffWaysToCompute(string input)
    {
        return do_compute(input, 0, input.size());
    }
};