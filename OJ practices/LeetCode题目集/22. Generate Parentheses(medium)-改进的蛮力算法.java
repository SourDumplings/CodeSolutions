import java.util.Arrays;
import java.util.List;

/*
 * @Author: SourDumplings
 * @Date: 2020-01-23 14:31:46
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/generate-parentheses/
 * 
 * 相较于蛮力算法，增加了一个剪枝
 * 即左括号的个数不能大于 n，右括号的数量不能大于左括号的数量
 * 即只会去生成有效的括号序列
 */

class Solution
{
    public List<String> generateParenthesis(int n)
    {
        List<String> res = new ArrayList<>();
        generateAll(new char[n * 2], 0, res, 0, 0, n);
        return res;
    }

    private void generateAll(char[] thisSeq, int i, List<String> res, int leftNum, int rightNum, int n)
    {
        if (i == n * 2)
        {
            res.add(new String(thisSeq));
        }
        else
        {
            if (leftNum < n)
            {
                thisSeq[i] = '(';
                generateAll(thisSeq, i + 1, res, leftNum + 1, rightNum, n);
            }
            if (rightNum < leftNum)
            {
                thisSeq[i] = ')';
                generateAll(thisSeq, i + 1, res, leftNum, rightNum + 1, n);
            }
        }
    }
}