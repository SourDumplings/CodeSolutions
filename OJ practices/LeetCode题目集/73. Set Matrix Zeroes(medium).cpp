/*
 * @Author: SourDumplings
 * @Date: 2020-07-13 20:29:15
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/set-matrix-zeroes/
 */ 

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        unordered_set<int> zeroRows, zeroCols;
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i != m; ++i)
        {
            for (int j = 0; j != n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    zeroRows.insert(i);
                    zeroCols.insert(j);
                }
            }
        }
        for (int r : zeroRows)
        {
            for (int c = 0; c != n; ++c)
            {
                matrix[r][c] = 0;
            }
        }
        for (int c : zeroCols)
        {
            for (int r = 0; r != m; ++r)
            {
                matrix[r][c] = 0;
            }
        }
    }
};