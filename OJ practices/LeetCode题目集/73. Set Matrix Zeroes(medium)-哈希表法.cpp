/**
 * @file 73. Set Matrix Zeroes(medium)-标记数组法.cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-04-09
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/set-matrix-zeroes/description/?envType=study-plan-v2&envId=top-interview-150
 * 
 */

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_set<int> zeroR;
        unordered_set<int> zeroC;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    zeroR.insert(i);
                    zeroC.insert(j);
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (zeroC.find(j) != zeroC.end()
                    || zeroR.find(i) != zeroR.end()
                )
                {
                    matrix[i][j] = 0;
                }
            }

        }

    }
};