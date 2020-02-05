import java.util.BitSet;

/*
 * @Author: SourDumplings
 * @Date: 2020-02-05 09:18:07
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/valid-sudoku/
 */

class Solution
{
    public boolean isValidSudoku(char[][] board)
    {
        return checkRows(board) && checkCols(board) && checkSub(board);
    }

    private boolean checkRows(char[][] board)
    {
        int l = 9;
        BitSet bs = new BitSet(l);
        for (int i = 0; i < l; i++)
        {
            bs.clear();
            for (int j = 0; j < l; j++)
            {
                char c = board[i][j];
                int no = c - '0' - 1;
                if (c != '.')
                {
                    if (bs.get(no))
                    {
                        return false;
                    }
                    else
                    {
                        bs.set(no);
                    }
                }
            }
        }
        return true;
    }

    private boolean checkCols(char[][] board)
    {
        int l = 9;
        BitSet bs = new BitSet(l);
        for (int i = 0; i < l; i++)
        {
            bs.clear();
            for (int j = 0; j < l; j++)
            {
                char c = board[j][i];
                int no = c - '0' - 1;
                if (c != '.')
                {
                    if (bs.get(no))
                    {
                        return false;
                    }
                    else
                    {
                        bs.set(no);
                    }
                }
            }
        }
        return true;
    }

    private boolean checkSub(char[][] board)
    {
        int l = 9, s = 3;
        BitSet bs = new BitSet(l);

        for (int i = 0; i < l; i++)
        {
            int r = (i / 3) * 3;
            int c = (i % 3) * 3;
            bs.clear();
            for (int j = 0; j < s; j++)
            {
                for (int k = 0; k < s; k++)
                {
                    char ch = board[j + r][k + c];
                    int no = ch - '0' - 1;
                    if (ch != '.')
                    {
                        if (bs.get(no))
                        {
                            return false;
                        }
                        else
                        {
                            bs.set(no);
                        }
                    }
                }
            }
        }

        return true;
    }
}