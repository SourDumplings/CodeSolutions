/**
 * @file 54. Spiral Matrix(medium).cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-04-06
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/spiral-matrix/description/?envType=study-plan-v2&envId=top-interview-150
 * 
 */

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        res.resize(m * n);
        int upperBound = 0, lowerBound = m - 1, leftBound = 0, rightBound = n - 1;
        char direction = 'r';
        int r = 0, c = 0;
        for (int i = 0; i < m * n; i++)
        {
            res[i] = matrix[r][c];
            switch (direction)
            {
            case 'r':
            {
                if (c == rightBound)
                {
                    direction = 'd';
                    ++upperBound;
                    ++r;
                }
                else
                {
                    ++c;
                }
                break;
            }
            case 'd':
            {
                if (r == lowerBound)
                {
                    direction = 'l';
                    --rightBound;
                    --c;
                }
                else
                {
                    ++r;
                }
                break;
            }
            case 'l':
            {
                if (c == leftBound)
                {
                    direction = 'u';
                    --lowerBound;
                    --r;
                }
                else
                {
                    --c;
                }
                break;
            }
            case 'u':
            {
                if (r == upperBound)
                {
                    direction = 'r';
                    ++leftBound;
                    ++c;
                }
                else
                {
                    --r;
                }
                break;
            }

            default:
                break;
            }
        }
        return res;
    }
};