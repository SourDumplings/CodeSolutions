import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/*
 * @Autor: SourDumplings
 * @Date: 2019-11-09 16:38:20
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/letter-case-permutation/
 * 
 * 用队列解决全排列问题
 */

class Solution
{
    public List<String> letterCasePermutation(String S)
    {
        int l = S.length();
        Queue<String> q = new LinkedList<>();
        q.add("");
        for (int i = 0; i < l; i++)
        {
            char c = S.charAt(i);
            int size = q.size();
            for (int j = 0; j < size; j++)
            {
                String str = q.poll();
                if (Character.isLetter(c))
                {
                    q.add(str + Character.toUpperCase(c));
                    q.add(str + Character.toLowerCase(c));
                }
                else
                {
                    q.add(str + c);
                }
            }
        }
        return new ArrayList<>(q);
    }
}