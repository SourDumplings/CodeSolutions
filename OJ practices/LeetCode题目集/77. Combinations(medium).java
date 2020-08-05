/*
 * @Author: SourDumplings
 * @Date: 2020-08-05 10:08:52
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/combinations/
 */

class Solution
{
    List<List<Integer>> res = new ArrayList<>();
    List<Integer> thisList = new ArrayList<>();

    public List<List<Integer>> combine(int n, int k)
    {
        for (int i = 1; i <= n; i++)
        {
            thisList.add(i);
            dfs(i, k - 1, n);
            thisList.remove(thisList.size() - 1);
        }
        return res;
    }

    private void dfs(int num, int count, int n)
    {
        if (count == 0)
        {
            res.add(new ArrayList<>(thisList));
            return;
        }
        for (int i = num + 1; i <= n; i++)
        {
            thisList.add(i);
            dfs(i, count - 1, n);
            thisList.remove(thisList.size() - 1);
        }
    }
}