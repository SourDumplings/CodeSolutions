import java.util.Stack;

/*
 * @Author: SourDumplings
 * @Date: 2019-10-14 19:53:01
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/baseball-game/
 */

class Solution
{
    public int calPoints(String[] ops)
    {
        Stack<Integer> S = new Stack<>();

        for (String op : ops)
        {
            if (op.equals("+"))
            {
                int top = S.pop();
                int newTop = top + S.peek();
                S.push(top);
                S.push(newTop);
            }
            else if (op.equals("C"))
            {
                S.pop();
            }
            else if (op.equals("D"))
            {
                S.push(S.peek() * 2);
            }
            else
            {
                S.push(Integer.valueOf(op));
            }
        }

        int res = 0;
        for (int i : S)
        {
            res += i;
        }
        return res;
    }
}