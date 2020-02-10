/*
 * @Author: SourDumplings
 * @Date: 2020-02-06 20:51:18
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/sudoku-solver/
 * 
 */

class Solution
{
    private final int l = 9;
    private boolean[][] rowTag = new boolean[l][l];
    private boolean[][] colTag = new boolean[l][l];
    private boolean[][] boxTag = new boolean[l][l];
    private boolean solved = false;

    public void solveSudoku(char[][] board)
    {
        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < l; j++)
            {
                rowTag[i][j] = colTag[i][j] = boxTag[i][j] = true;
            }
        }

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < l; j++)
            {
                if (board[i][j] != '.')
                {
                    int d = board[i][j] - '1';
                    rowTag[i][d] = false;
                    colTag[j][d] = false;
                    boxTag[i / 3 * 3 + j / 3][d] = false;
                }
            }
        }

        backtrack(board, 0, 0);
    }

    private boolean couldPlace(int d, int r, int c)
    {
        return rowTag[r][d] && colTag[c][d] && boxTag[r / 3 * 3 + c / 3][d];
    }

    private void placeNum(char[][] board, int d, int r, int c)
    {
        rowTag[r][d] = colTag[c][d] = boxTag[r / 3 * 3 + c / 3][d] = false;
        board[r][c] = (char) (d + '1');
    }

    private void removeNum(char[][] board, int d, int r, int c)
    {
        rowTag[r][d] = colTag[c][d] = boxTag[r / 3 * 3 + c / 3][d] = true;
        board[r][c] = '.';
    }

    private void placeNextNum(char[][] board, int r, int c)
    {
        if (r == l - 1 && c == l - 1)
        {
            solved = true;
            return;
        }
        else if (c == l - 1)
        {
            c = 0;
            ++r;
        }
        else
        {
            ++c;
        }
        backtrack(board, r, c);
    }

    private void backtrack(char[][] board, int r, int c)
    {
        if (board[r][c] == '.')
        {
            for (int i = 0; i < l; i++)
            {
                if (couldPlace(i, r, c))
                {
                    placeNum(board, i, r, c);
                    placeNextNum(board, r, c);
                    if (solved)
                    {
                        return;
                    }
                    else
                    {
                        removeNum(board, i, r, c);
                    }
                }
            }
        }
        else
        {
            placeNextNum(board, r, c);
        }
    }
}