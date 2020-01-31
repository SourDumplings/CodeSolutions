import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
 * @Author: SourDumplings
 * @Date: 2020-01-17 10:03:14
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/letter-combinations-of-a-phone-number/
 */

class Solution
{
    public List<String> letterCombinations(String digits)
    {
        String[] A = new String[]
        { null, null, "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        int l = digits.length();
        Queue<StringBuilder> temp = new LinkedList<>();
        boolean first = true;
        for (int i = 0; i < l; i++)
        {
            int d = digits.charAt(i) - '0';
            String letters = A[d];
            int ll = letters.length();
            StringBuilder sb = null;
            if (first)
            {
                first = false;
                sb = new StringBuilder();
                for (int j = 0; j < ll; j++)
                {
                    char c = letters.charAt(j);
                    temp.add(new StringBuilder(sb).append(c));
                }
            }
            else
            {
                Queue<StringBuilder> tempQ = new LinkedList<>();
                while (!temp.isEmpty())
                {
                    sb = temp.poll();
                    for (int j = 0; j < ll; j++)
                    {
                        char c = letters.charAt(j);
                        tempQ.add(new StringBuilder(sb).append(c));
                    }
                }
                temp = tempQ;
            }

        }
        List<String> res = new ArrayList<>();
        for (StringBuilder sb : temp)
        {
            res.add(sb.toString());
        }
        return res;
    }
}