import java.util.Arrays;
import java.util.List;

/*
 * @Author: SourDumplings
 * @Date: 2020-01-20 10:03:06
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/generate-parentheses/
 * 
 * 产生所有可能的括号组合，然后筛选出有效的组合
 */

class Solution
{
    public List<String> generateParenthesis(int n)
    {
        List<String> res = new ArrayList<>();
        generateAll(new char[n * 2], 0, res);
        return res;
    }

    private void generateAll(char[] thisSeq, int i, List<String> res)
    {
        if (i == thisSeq.length)
        {
            if (valid(thisSeq))
            {
                res.add(new String(thisSeq));
            }
        }
        else
        {
            thisSeq[i] = '(';
            generateAll(thisSeq, i + 1, res);
            thisSeq[i] = ')';
            generateAll(thisSeq, i + 1, res);
        }
    }

    private boolean valid(char[] thisSeq)
    {
        int countLeft = 0;
        for (char c : thisSeq)
        {
            if (c == '(')
            {
                ++countLeft;
            }
            else
            {
                if (countLeft == 0)
                {
                    return false;
                }
                --countLeft;
            }
        }
        return countLeft == 0;
    }
}