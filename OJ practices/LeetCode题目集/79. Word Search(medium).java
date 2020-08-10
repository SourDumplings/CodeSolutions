/*
 * @Author: SourDumplings
 * @Date: 2020-08-09 17:30:55
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/word-search/
 */

class Solution
{
    int n, m;
    boolean[][] visited;

    public boolean exist(char[][] board, String word)
    {
        n = board.length;
        m = board[0].length;
        visited = new boolean[n][m];
        for (int k = 0; k < n; k++)
        {
            for (int l = 0; l < m; l++)
            {
                visited[k][l] = false;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (board[i][j] == word.charAt(0))
                {

                    visited[i][j] = true;
                    final boolean res = dfs(board, word, i, j, 1);
                    if (res)
                    {
                        return true;
                    }
                    visited[i][j] = false;
                }
            }
        }
        return false;
    }

    private boolean dfs(char[][] board, String word, int startI, int startJ, int nextCIndex)
    {
        if (nextCIndex == word.length())
        {
            return true;
        }
        else
        {
            char c = word.charAt(nextCIndex);
            if (startI < n - 1 && !visited[startI + 1][startJ] && board[startI + 1][startJ] == c)
            {
                visited[startI + 1][startJ] = true;
                final boolean res = dfs(board, word, startI + 1, startJ, nextCIndex + 1);
                if (res)
                {
                    return true;
                }
                visited[startI + 1][startJ] = false;
            }
            if (startI > 0 && !visited[startI - 1][startJ] && board[startI - 1][startJ] == c)
            {
                visited[startI - 1][startJ] = true;
                final boolean res = dfs(board, word, startI - 1, startJ, nextCIndex + 1);
                if (res)
                {
                    return true;
                }
                visited[startI - 1][startJ] = false;
            }
            if (startJ < m - 1 && !visited[startI][startJ + 1] && board[startI][startJ + 1] == c)
            {
                visited[startI][startJ + 1] = true;
                final boolean res = dfs(board, word, startI, startJ + 1, nextCIndex + 1);
                if (res)
                {
                    return true;
                }
                visited[startI][startJ + 1] = false;
            }
            if (startJ > 0 && !visited[startI][startJ - 1] && board[startI][startJ - 1] == c)
            {
                visited[startI][startJ - 1] = true;
                final boolean res = dfs(board, word, startI, startJ - 1, nextCIndex + 1);
                if (res)
                {
                    return true;
                }
                visited[startI][startJ - 1] = false;
            }
        }
        return false;
    }
}