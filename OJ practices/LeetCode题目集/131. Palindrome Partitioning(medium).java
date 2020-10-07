/*
 * @Author: SourDumplings
 * @Date: 2020-10-07 16:07:48
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/palindrome-partitioning/
 */

class Solution
{
    private boolean[][] isPal;
    private List<List<String>> res;
    private List<String> thisList;

    public List<List<String>> partition(String s)
    {
        int l = s.length();
        isPal = new boolean[l][l];
        res = new ArrayList<>();
        thisList = new ArrayList<>();
        if (l == 0)
        {
            return res;
        }
        for (int i = 0; i < l; i++)
        {
            preTreat(isPal, s, i, l);
        }
        backtrack(s, 0, l);
        return res;
    }

    private void preTreat(boolean[][] isPal, String s, int start, int l)
    {
        for (int end = start + 1; end <= l; ++end)
        {
            int e = (start + end) / 2;
            isPal[start][end - 1] = true;
            for (int i = start; i < e; i++)
            {
                if (s.charAt(i) != s.charAt(end - i + start - 1))
                {
                    isPal[start][end - 1] = false;
                    break;
                }
            }
        }
    }

    private void backtrack(String s, int start, int l)
    {
        if (start == l)
        {
            res.add(new ArrayList<>(thisList));
        }
        else
        {
            for (int i = start; i < l; i++)
            {
                if (isPal[start][i])
                {
                    thisList.add(s.substring(start, i + 1));
                    backtrack(s, i + 1, l);
                    thisList.remove(thisList.size() - 1);
                }
            }
        }
    }
}
