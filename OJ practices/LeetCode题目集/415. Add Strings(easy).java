/*
 * @Author: SourDumplings
 * @Date: 2019-09-24 16:48:15
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/add-strings/
 */

class Solution
{
    public String addStrings(String num1, String num2)
    {
        int l1 = num1.length();
        int l2 = num2.length();
        if (l1 < l2)
        {
            int temp = l1;
            l1 = l2;
            l2 = temp;
            String sTemp = num1;
            num1 = num2;
            num2 = sTemp;
        }
        StringBuilder sb = new StringBuilder();
        boolean isCarry = false;
        for (int i = l2 - 1; i >= 0; i--)
        {
            char c1 = num1.charAt(i + l1 - l2);
            char c2 = num2.charAt(i);
            isCarry = doSum(sb, c1, c2, isCarry);
        }
        for (int i = l1 - l2 - 1; i >= 0; i--)
        {
            char c = num1.charAt(i);
            isCarry = doSum(sb, c, '0', isCarry);
        }
        if (isCarry)
        {
            sb.append('1');
        }
        return sb.reverse().toString();
    }

    boolean doSum(StringBuilder sb, char a, char b, boolean isCarry)
    {
        int r = a - '0' + b - '0';
        if (isCarry)
        {
            r++;
            isCarry = false;
        }
        if (r > 9)
        {
            r -= 10;
            isCarry = true;
        }
        sb.append(r);
        return isCarry;
    }
}