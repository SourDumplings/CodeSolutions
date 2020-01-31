/*
 * @Author: SourDumplings
 * @Date: 2020-01-06 18:59:14
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/zigzag-conversion/
 */

class Solution
{
    public String convert(String s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }
        int numCols = 500;
        Character[][] a = new Character[numRows][numCols];
        int l = s.length();
        int r = 0, c = 0;
        boolean downMove = true;
        for (int i = 0; i < l; i++)
        {
            Character ch = s.charAt(i);
            a[r][c] = ch;
            if (downMove)
            {
                if (r == numRows - 1)
                {
                    ++c;
                    --r;
                    downMove = false;
                }
                else
                {
                    ++r;
                }
            }
            else
            {
                if (r == 0)
                {
                    downMove = true;
                    ++r;
                }
                else
                {
                    --r;
                    ++c;
                }
            }
        }
        StringBuilder sb = new StringBuilder();
        int count = 0;
        for (int i = 0; i < numRows; i++)
        {
            for (int j = 0; j < numCols; j++)
            {
                Character ch = a[i][j];
                if (ch != null)
                {
                    sb.append(ch);
                    ++count;
                }
                if (count == l)
                {
                    return sb.toString();
                }
            }
        }
        return null;
    }
}