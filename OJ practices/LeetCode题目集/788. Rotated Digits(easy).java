/*
 * @Author: SourDumplings
 * @Date: 2019-11-11 17:48:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/rotated-digits/
 * 
 * 遍历每个数字，对每个数字的每一位遍历
 * 满足条件的数字必须至少含一位2，5，6，9，
 * 且不能含3，4，7
 */

class Solution
{
    public int rotatedDigits(int N)
    {
        int res = 0;
        for (int i = 1; i <= N; ++i)
        {
            int num = i;
            int count = 0;
            do
            {
                int d = num % 10;
                if (d == 2 || d == 5 || d == 6 || d == 9)
                {
                    ++count;
                }
                else if (d == 3 || d == 7 || d == 4)
                {
                    count = 0;
                    break;
                }
                num /= 10;
            }
            while (num != 0);
            if (count > 0)
            {
                ++res;
            }
        }
        return res;
    }
}