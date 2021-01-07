/*
 * @Author: SourDumplings
 * @Date: 2021-01-07 16:31:02
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/basic-calculator-ii/
 * 
 * 参考：https://leetcode-cn.com/problems/basic-calculator-ii/solution/chai-jie-fu-za-wen-ti-shi-xian-yi-ge-wan-zheng-ji-/
 */

class Solution
{
private:
    int l;
public:
    int calculate(string s)
    {
        int begin = 0;
        l = s.length();
        return calHelper(s, begin);
    }
    int calHelper(string s, int i) // i用于记录计算开始的索引
    {
        char operation = '+';
        stack<int> nums;
        int num = 0;
        int res = 0;
        for (; i < l; i++)
        {
            if (isdigit(s[i]))
            {
                num = num * 10 + (s[i] - '0');
            }
            else if (s[i] == '(')
            {
                num = calHelper(s, ++i); // 从 i 的下一个开始计算， 进入递归
                i++; // 计算完之后的 i 指向)所以再++
            }
            if ((!isdigit(s[i]) && s[i] != ' ') || i >= l - 1)
            {
                // s[i] 是运算符或者是最后一个字符
                int pre = 0;
                switch (operation)
                {
                    case '+':
                        nums.push(num);
                        break;
                    case '-':
                        nums.push(-num);
                        break;
                    case '*':
                        pre = nums.top();
                        nums.pop();
                        nums.push(pre * num);
                        break;
                    case '/':
                        pre = nums.top();
                        nums.pop();
                        nums.push(pre / num);
                        break;
                }

                operation = s[i];
                num = 0;
            }
            if (s[i] == ')') // 遇到)回到上一级递归
            {
                break;
            }
        }
        while (!nums.empty())
        {
            res += nums.top();
            nums.pop();
        }
        return res;
    }
};