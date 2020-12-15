/*
 * @Author: SourDumplings
 * @Date: 2020-12-15 09:40:26
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/fraction-to-recurring-decimal/
 * 
 * 使用长除法，参考：https://leetcode-cn.com/problems/fraction-to-recurring-decimal/solution/fen-shu-dao-xiao-shu-by-leetcode/
 */

class Solution
{
public:
    string fractionToDecimal(int numerator, int denominator)
    {
        if (numerator == 0)
        {
            return "0";
        }
        string fraction;
        // 考虑负数情况，这里的异或非常巧妙
        if (numerator < 0 ^ denominator < 0)
        {
            fraction += '-';
        }

        // 使用长除法
        // 先算整数部分，要将分子分母转为长整型
        long long dividend = abs(numerator);
        long long divisor = abs(denominator);
        fraction += to_string(dividend / divisor);
        long long remainder = dividend % divisor;
        if (remainder == 0)
        {
            return fraction;
        }
        // 再算小数部分
        fraction.append(".");
        // 记录循环节的位置
        unordered_map<long long, int> m;
        while (remainder != 0)
        {
            if (m.find(remainder) != m.end())
            {
                // 出现了循环
                fraction.insert(m[remainder], "(");
                fraction += ")";
                break;
            }
            m[remainder] = fraction.length();
            remainder *= 10;
            fraction += to_string(remainder / divisor);
            remainder %= divisor;
        }
        return fraction;
    }

};