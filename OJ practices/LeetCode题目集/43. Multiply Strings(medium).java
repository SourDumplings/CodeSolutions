/*
 * @Author: SourDumplings
 * @Date: 2020-02-23 10:46:25
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/multiply-strings/
 */

class Solution
{
    private int l1, l2;

    public String multiply(String num1, String num2)
    {
        l1 = num1.length();
        l2 = num2.length();
        String res = "0";
        for (int i = l2 - 1; 0 <= i; --i)
        {
            int d = num2.charAt(i) - '0';
            String prod = multi(num1, d, l2 - i - 1);
            res = add(res, prod);
        }
        int nonZero = 0;
        for (; nonZero != res.length() && res.charAt(nonZero) == '0'; ++nonZero)
        {
        }
        if (nonZero == res.length())
        {
            nonZero = res.length() - 1;
        }
        return res.substring(nonZero);
    }

    private String multi(String num, int f, int base)
    {
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        for (int i = l1 - 1; 0 <= i; --i)
        {
            int d = num.charAt(i) - '0';
            int p = d * f;
            int thisD = p % 10 + carry;
            carry = p / 10;
            if (9 < thisD)
            {
                thisD %= 10;
                ++carry;
            }
            sb.append(thisD);
        }
        if (0 < carry)
        {
            sb.append(carry);
        }
        sb.reverse();
        for (int i = 0; i < base; i++)
        {
            sb.append(0);
        }
        return sb.toString();
    }

    private String add(String res, String prod)
    {
        int lr = res.length();
        int lp = prod.length();
        StringBuilder sb = new StringBuilder();
        int carry = 0;
        int i = lp - 1, j = lr - 1;
        for (; 0 <= i && 0 <= j; --i, --j)
        {
            int d = res.charAt(j) - '0' + prod.charAt(i) - '0' + carry;
            carry = 0;
            if (9 < d)
            {
                ++carry;
                d %= 10;
            }
            sb.append(d);
        }
        for (; 0 <= i; --i)
        {
            int d = prod.charAt(i) - '0' + carry;
            carry = 0;
            if (9 < d)
            {
                ++carry;
                d %= 10;
            }
            sb.append(d);
        }
        for (; 0 <= j; --j)
        {
            int d = res.charAt(j) - '0' + carry;
            carry = 0;
            if (9 < d)
            {
                ++carry;
                d %= 10;
            }
            sb.append(d);
        }
        if (0 < carry)
        {
            sb.append(carry);
        }
        return sb.reverse().toString();
    }
}
