/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/pascals-triangle/
 * @Date: 2019-03-09 19:25:36
 */

class Solution
{
  public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> res;
        res.resize(numRows);
        for (int i = 0; i < numRows; i++)
        {
            res[i].resize(i + 1);
            for (int j = 0; j < i + 1; j++)
            {
                if (j == 0 || j == i)
                {
                    res[i][j] = 1;
                }
                else
                {
                    res[i][j] = res[i - 1][j] + res[i - 1][j - 1];
                }
            }
        }
        return res;
    }
};