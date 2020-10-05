/*
 * @Author: SourDumplings
 * @Date: 2020-10-05 11:48:32
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/surrounded-regions/
 */

class Solution
{
    private int m;
    private int n;
    boolean[][] flag;

    public void solve(char[][] board)
    {
        m = board.length;
        if (m == 0)
        {
            return;
        }
        n = board[0].length;
        flag = new boolean[m][n];
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                flag[i][j] = false;
            }
        }
        for (int i = 0; i < m; i++)
        {
            if (board[i][0] == 'O')
            {
                dfs(board, i, 0);
            }
            if (board[i][n - 1] == 'O')
            {
                dfs(board, i, n - 1);
            }
        }
        for (int i = 1; i < n - 1; i++)
        {
            if (board[0][i] == 'O')
            {
                dfs(board, 0, i);
            }
            if (board[m - 1][i] == 'O')
            {
                dfs(board, m - 1, i);
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (!flag[i][j])
                {
                    board[i][j] = 'X';
                }
            }
        }
    }

    private void dfs(char[][] board, int x, int y)
    {
        flag[x][y] = true;
        if (x > 0 && board[x - 1][y] == 'O' && !flag[x - 1][y])
        {
            dfs(board, x - 1, y);
        }
        if (x < m - 1 && board[x + 1][y] == 'O' && !flag[x + 1][y])
        {
            dfs(board, x + 1, y);
        }
        if (y > 0 && board[x][y - 1] == 'O' && !flag[x][y - 1])
        {
            dfs(board, x, y - 1);
        }
        if (y < n - 1 && board[x][y + 1] == 'O' && !flag[x][y + 1])
        {
            dfs(board, x, y + 1);
        }
    }
}