/**
 * @file 48. Rotate Image(medium)-模拟旋转.cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief https://leetcode.cn/problems/rotate-image/submissions/521135018/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-04-07
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 */

class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = n; i > 1; i -= 2)
        {
            rotate_annular(matrix, i);
        }
    }

private:
    void rotate_annular(vector<vector<int>> &matrix, int l)
    {
        int n = matrix.size();
        int startR = (n - l) / 2;
        int startC = (n - l) / 2;
        for (int count = 0; count < l - 1; ++count)
        {
            int thisR = startR;
            int thisC = startC + count;
            int last = matrix[thisR][thisC];
            int r, c;
            for (int k = 0; k < 4; ++k)
            {
                switch (k)
                {
                case 0:
                {
                    r = startR + count;
                    c = startC + l - 1;
                    break;
                }
                case 1:
                {
                    r = startR + l - 1;
                    c = startC + l - 1 - count;
                    break;
                }
                case 2:
                {
                    r = startR + l - 1 - count;
                    c = startC;
                    break;
                }
                case 3:
                {
                    r = startR;
                    c = startC + count;
                    break;
                }

                default:
                    break;
                }
                int temp = matrix[r][c];
                matrix[r][c] = last;
                last = temp;
            }
        }
    }
};
