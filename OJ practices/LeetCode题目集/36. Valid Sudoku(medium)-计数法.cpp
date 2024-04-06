/**
 * @file 36. Valid Sudoku(medium)-计数法.cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-04-06
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/valid-sudoku/solutions/1001859/you-xiao-de-shu-du-by-leetcode-solution-50m6/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        // 数组，分别记录 1 ~ 9 这些数字在各行、各咧，各小矩阵中出现的次数
        int r[9][9], c[9][9], sub[3][3][9];
        memset(r, 0, sizeof(r));
        memset(c, 0, sizeof(c));
        memset(sub, 0, sizeof(sub));
        for (int i = 0; i < 9; ++i)
        {
            for (int j = 0; j < 9; j++)
            {
                char ch = board[i][j];
                if (ch == '.')
                {
                    continue;
                }
                int num = ch - '1';
                if (0 < r[i][num] + c[j][num] + sub[i / 3][j / 3][num])
                {
                    return false;
                }
                ++r[i][num];
                ++c[j][num];
                ++sub[i / 3][j / 3][num];
            }
        }
        return true;
    }
};