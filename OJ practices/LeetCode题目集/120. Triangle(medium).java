/*
 * @Author: SourDumplings
 * @Date: 2020-10-02 09:13:10
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/triangle/
 */

class Solution
{

    public int minimumTotal(List<List<Integer>> triangle)
    {
        int levelNum = triangle.size();
        List<int[]> f = new ArrayList<>();
        for (int i = 0; i < levelNum; i++)
        {
            f.add(new int[i + 1]);
        }
        for (int i = 0; i < levelNum; i++)
        {
            (f.get(levelNum - 1))[i] = triangle.get(levelNum - 1).get(i);
        }
        for (int i = levelNum - 2; i >= 0; i--)
        {
            for (int j = 0; j < i + 1; j++)
            {
                int thisNum = triangle.get(i).get(j);
                (f.get(i))[j] = thisNum + Math.min((f.get(i + 1))[j], (f.get(i + 1))[j + 1]);
            }
        }
        return (f.get(0))[0];
    }

}