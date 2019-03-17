/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/pascals-triangle/
 * @Date: 2019-03-09 19:32:32
 */

class Solution
{
    public List<List<Integer>> generate(int numRows)
    {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        for (int i = 0; i < numRows; ++i)
        {
            res.add(i, new ArrayList<Integer>());
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                    res.get(i).add(j, 1);
                else
                    res.get(i).add(j, res.get(i - 1).get(j) + res.get(i - 1).get(j - 1));
            }
        }
        return res;
    }
}