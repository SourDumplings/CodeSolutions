import java.util.Arrays;
import java.util.BitSet;

/*
 * @Author: SourDumplings
 * @Date: 2019-11-08 18:37:30
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/jewels-and-stones/
 */

class Solution
{
    public int numJewelsInStones(String J, String S)
    {
        BitSet jewels = new BitSet(52);
        int lJ = J.length();
        int lS = S.length();
        for (int i = 0; i < lJ; i++)
        {
            char c = J.charAt(i);
            if (Character.isLowerCase(c))
            {
                jewels.set(c - 'a');
            }
            else
            {
                jewels.set(c - 'A' + 26);
            }
        }
        int res = 0;
        for (int i = 0; i < lS; i++)
        {
            char c = S.charAt(i);
            if (Character.isLowerCase(c))
            {
                res += jewels.get(c - 'a') ? 1 : 0;
            }
            else
            {
                res += jewels.get(c - 'A' + 26) ? 1 : 0;
            }
        }
        return res;
    }
}