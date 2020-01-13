/*
 * @Autor: SourDumplings
 * @Date: 2020-01-13 22:14:04
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/integer-to-roman/
 */

class Solution
{
    public String intToRoman(int num)
    {
        StringBuilder sb = new StringBuilder();
        // 千位
        while (num >= 1000)
        {
            num -= 1000;
            sb.append("M");
        }

        // 百位
        if (num >= 100)
        {
            if (num < 400)
            {
                while (num >= 100)
                {
                    num -= 100;
                    sb.append("C");
                }
            }
            else if (num < 500)
            {
                num -= 400;
                sb.append("CD");
            }
            else if (num < 900)
            {
                num -= 500;
                sb.append("D");
                while (num >= 100)
                {
                    num -= 100;
                    sb.append("C");
                }
            }
            else
            {
                num -= 900;
                sb.append("CM");
            }
        }

        // 十位
        if (num >= 10)
        {
            if (num < 40)
            {
                while (num >= 10)
                {
                    num -= 10;
                    sb.append("X");
                }
            }
            else if (num < 50)
            {
                num -= 40;
                sb.append("XL");
            }
            else if (num < 90)
            {
                num -= 50;
                sb.append("L");
                while (num >= 10)
                {
                    num -= 10;
                    sb.append("X");
                }
            }
            else
            {
                num -= 90;
                sb.append("XC");
            }
        }

        // 个位
        if (num >= 1)
        {
            if (num < 4)
            {
                while (num >= 1)
                {
                    num -= 1;
                    sb.append("I");
                }
            }
            else if (num < 5)
            {
                num -= 4;
                sb.append("IV");
            }
            else if (num < 9)
            {
                num -= 5;
                sb.append("V");
                while (num >= 1)
                {
                    num -= 1;
                    sb.append("I");
                }
            }
            else
            {
                num -= 9;
                sb.append("IX");
            }
        }
        return sb.toString();
    }
}
