import java.util.ArrayList;
import java.util.List;

/*
 * @Autor: SourDumplings
 * @Date: 2019-09-27 17:03:21
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/keyboard-row/
 */

class Solution
{
    public String[] findWords(String[] words)
    {
        int[][] info =
        {
                { 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p' },
                { 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l' },
                { 'z', 'x', 'c', 'v', 'b', 'n', 'm' } };
        int[] h = new int[26];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                if (i == 1 && j == 9 || i == 2 && j == 7)
                {
                    break;
                }
                h[info[i][j] - 'a'] = i;
            }
        }
        List<String> res = new ArrayList<>();
        for (String s : words)
        {
            String sl = s.toLowerCase();
            int r = h[sl.charAt(0) - 'a'];
            boolean flag = true;
            int l = s.length();
            for (int i = 0; i < l; ++i)
            {
                char c = sl.charAt(i);
                if (h[c - 'a'] != r)
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                res.add(s);
            }
        }
        String[] realRes = new String[res.size()];
        int i = 0;
        for (String s : res)
        {
            realRes[i++] = s;
        }
        return realRes;
    }
}