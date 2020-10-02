/*
 * @Author: SourDumplings
 * @Date: 2020-10-02 10:18:15
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/triangle/
 */

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<vector<int>> f;
        int levelNum = triangle.size();
        for (int i = 0; i < levelNum; i++)
        {
            f.push_back(vector<int>(i + 1));
        }
        for (int i = 0; i < levelNum; i++)
        {
            f[levelNum - 1][i] = triangle[levelNum - 1][i];
        }
        for (int i = levelNum - 2; i >= 0; i--)
        {
            for (int j = 0; j < i + 1; j++)
            {
                f[i][j] = triangle[i][j] + min(f[i + 1][j], f[i + 1][j + 1]);
            }
            
        }
        return f[0][0];
    }
};