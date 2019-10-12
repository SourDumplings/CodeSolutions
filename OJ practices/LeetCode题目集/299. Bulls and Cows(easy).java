import java.util.Arrays;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-08 22:43:55
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/bulls-and-cows/
 */

class Solution
{
    public String getHint(String secret, String guess)
    {
        int[] s = new int[11];
        int[] g = new int[11];
        Arrays.fill(s, 0);
        Arrays.fill(g, 0);
        int bulls = 0;
        int cows = 0;
        int l = secret.length();
        for (int i = 0; i < l; i++)
        {
            char sc = secret.charAt(i);
            char gc = guess.charAt(i);
            if (sc == gc)
            {
                ++bulls;
            }
            else
            {
                ++s[sc - '0'];
                ++g[gc - '0'];
            }
        }
        for (int i = 0; i < 10; i++)
        {
            if (g[i] > s[i])
            {
                cows += s[i];
            }
            else
            {
                cows += g[i];
            }
        }
        StringBuilder stringBuilder = new StringBuilder();
        stringBuilder.append(((Integer) bulls).toString());
        stringBuilder.append("A");
        stringBuilder.append(((Integer) cows).toString());
        stringBuilder.append("B");
        return stringBuilder.toString();
    }
}