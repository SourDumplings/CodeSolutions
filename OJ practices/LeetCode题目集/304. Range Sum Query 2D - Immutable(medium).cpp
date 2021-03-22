/*
 * @Author: SourDumplings
 * @Date: 2021-03-22 10:56:23
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
 */

class NumMatrix
{
private:
    vector<vector<int>> matSum;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        matSum.resize(m);
        for (int i = 0; i < m; ++i)
        {
            matSum[i].resize(n);
            for (int j = 0; j < n; ++j)
            {
                matSum[i][j] = matrix[i][j];
                if (j > 0)
                {
                    matSum[i][j] += matSum[i][j - 1];
                }
                if (i > 0)
                {
                    matSum[i][j] += matSum[i - 1][j];
                }
                if (i > 0 && j > 0)
                {
                    matSum[i][j] -= matSum[i - 1][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int res = matSum[row2][col2];
        if (row1 > 0)
        {
            res -= matSum[row1 - 1][col2];
        }
        if (col1 > 0)
        {
            res -= matSum[row2][col1 - 1];
        }
        if (row1 > 0 && col1 > 0)
        {
            res += matSum[row1 - 1][col1 - 1];
        }
        return res;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
