/**
 * @file 73. Set Matrix Zeroes(medium)-就地标记行列法.cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-04-09
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 使用数组中将被置为 0 的行列标记要被置为 0 的行列，即哈希表
 * 复杂度：时间 O(mn)，空间 O(1)
 * 
 * https://leetcode.cn/problems/set-matrix-zeroes/solutions/669901/ju-zhen-zhi-ling-by-leetcode-solution-9ll7/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int zeroR = -1, zeroC = -1;
        for (int i = 0; i < m && zeroR == -1; i++)
        {
            for (int j = 0; j < n; ++j)
            {
                if (matrix[i][j] == 0)
                {
                    zeroR = i;
                    zeroC = j;
                    break;
                }
            }
        }
        if (zeroR == -1)
        {
            return;
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[zeroR][j] = 0;
                    matrix[i][zeroC] = 0;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            if (i == zeroR)
            {
                continue;
            }
            
            for (int j = 0; j < n; j++)
            {
                if (j == zeroC)
                {
                    continue;
                }

                if (matrix[i][zeroC] == 0
                    || matrix[zeroR][j] == 0
                )
                {
                    matrix[i][j] = 0;
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            matrix[i][zeroC] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            matrix[zeroR][i] = 0;
        }
        
    }
};