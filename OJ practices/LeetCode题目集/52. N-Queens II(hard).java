/*
 * @Author: SourDumplings
 * @Date: 2020-03-12 22:08:38
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/n-queens-ii/
 */

class Solution
{
    int rows[];
    // "hill" diagonals 主对角线
    int hills[];
    // "dale" diagonals 次对角线
    int dales[];
    int n;
    // output
    int output = 0;
    // queens positions
    // 记录每一行的皇后在哪一列
    int queens[];

    private boolean isNotUnderAttack(int row, int col)
    {
        int res = rows[col] + hills[row - col + 2 * n] + dales[row + col];
        return (res == 0) ? true : false;
    }

    private void placeQueen(int row, int col)
    {
        queens[row] = col;
        rows[col] = 1;
        hills[row - col + 2 * n] = 1; // "hill" diagonals
        dales[row + col] = 1; //"dale" diagonals
    }

    private void removeQueen(int row, int col)
    {
        rows[col] = 0;
        hills[row - col + 2 * n] = 0; // "hill" diagonals
        dales[row + col] = 0; //"dale" diagonals
    }

    private void backtrack(int row)
    {
        for (int col = 0; col < n; col++)
        {
            if (isNotUnderAttack(row, col))
            {
                placeQueen(row, col);
                // if n queens are already placed
                if (row + 1 == n)
                    ++output;
                // if not proceed to place the rest
                else
                    backtrack(row + 1);
                // backtrack
                removeQueen(row, col);
            }
        }
    }

    public int totalNQueens(int n)
    {
        this.n = n;
        rows = new int[n];
        hills = new int[4 * n - 1];
        dales = new int[2 * n - 1];
        queens = new int[n];

        // 从第 0 行开始
        backtrack(0);
        return output;
    }
}
