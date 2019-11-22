/*
 * @Autor: SourDumplings
 * @Date: 2019-11-22 21:20:01
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/number-of-lines-to-write-string/
 */

class Solution
{
    public int[] numberOfLines(int[] widths, String S)
    {
        int lineNum = 1;
        int l = S.length();
        int thisLineRes = 100;
        for (int i = 0; i < l; i++)
        {
            int needUnits = widths[S.charAt(i) - 'a'];
            if (thisLineRes < needUnits)
            {
                thisLineRes = 100;
                lineNum++;
            }
            thisLineRes -= needUnits;
        }
        return new int[]
        { lineNum, 100 - thisLineRes };
    }
}