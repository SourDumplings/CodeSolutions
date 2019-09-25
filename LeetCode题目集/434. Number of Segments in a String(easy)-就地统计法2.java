/*
 * @Autor: SourDumplings
 * @Date: 2019-09-25 11:46:56
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/number-of-segments-in-a-string/
 */

class Solution
{
    public int countSegments(String s)
    {
        int res = 0;
        boolean firstC = true;
        int l = s.length();
        for (int i = 0; i < l; i++)
        {
            if (s.charAt(i) != ' ')
            {
                if (firstC)
                {
                    ++res;
                    firstC = false;
                }
            }
            else
            {
                firstC = true;
            }
        }
        return res;
    }
}