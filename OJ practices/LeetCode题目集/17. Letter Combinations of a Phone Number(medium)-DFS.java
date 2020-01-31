import java.util.ArrayList;
import java.util.List;

/*
 * @Author: SourDumplings
 * @Date: 2020-01-17 11:08:40
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 */

class Solution
{
    private String[] A = new String[]
    { null, null, "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

    public List<String> letterCombinations(String digits)
    {
        List<String> res = new ArrayList<>();

        if (!digits.isEmpty())
        {
            DFS(new StringBuilder(), digits, res);
        }
        return res;
    }

    private void DFS(StringBuilder sb, String digits, List<String> res)
    {
        if (digits.isEmpty())
        {
            res.add(sb.toString());
        }
        else
        {
            int d = digits.charAt(0) - '0';
            String letters = A[d];
            int l = letters.length();
            for (int i = 0; i < l; i++)
            {
                char c = letters.charAt(i);
                DFS(new StringBuilder(sb).append(c), digits.substring(1), res);
            }
        }
    }
}