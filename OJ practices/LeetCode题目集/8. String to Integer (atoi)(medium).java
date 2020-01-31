/*
 * @Author: SourDumplings
 * @Date: 2020-01-07 21:34:23
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/string-to-integer-atoi/
 */

class Solution
{
    public int myAtoi(String str)
    {
        int res = 0;
        str = str.trim();
        int l = str.length();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < l; i++)
        {
            Character c = str.charAt(i);
            if (i == 0)
            {
                if (c == '-')
                {
                    sb.append(c);
                }
                else if (c != '+' && !Character.isDigit(c))
                {
                    break;
                }
            }
            if (Character.isDigit(c))
            {
                sb.append(c);
            }
            else if (i != 0)
            {
                break;
            }
        }
        String valueStr = sb.toString();
        if (valueStr.length() == 0 || valueStr.equals("-"))
        {
            return 0;
        }
        Double value = Double.parseDouble(valueStr);
        if (value > Integer.MAX_VALUE)
        {
            res = Integer.MAX_VALUE;
        }
        else if (value < Integer.MIN_VALUE)
        {
            res = Integer.MIN_VALUE;
        }
        else
        {
            res = Integer.parseInt(valueStr);
        }
        return res;
    }
}
