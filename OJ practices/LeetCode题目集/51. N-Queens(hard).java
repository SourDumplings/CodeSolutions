import java.util.ArrayList;
import java.util.List;

/*
 * @Author: SourDumplings
 * @Date: 2020-03-09 10:32:37
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/n-queens/
 * 
 * 一行只可能有一个皇后且一列也只可能有一个皇后
 * 这意味着没有必要再棋盘上考虑所有的方格。只需要按列循环即可
 * 对于所有的主对角线有 行号 + 列号 = 常数，对于所有的次对角线有 行号 - 列号 = 常数
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
    List<List<String>> output = new ArrayList<>();
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

    private void addSolution()
    {
        List<String> solution = new ArrayList<>();
        for (int i = 0; i < n; ++i)
        {
            int col = queens[i];
            StringBuilder sb = new StringBuilder();
            for (int j = 0; j < col; ++j)
                sb.append(".");
            sb.append("Q");
            for (int j = 0; j < n - col - 1; ++j)
                sb.append(".");
            solution.add(sb.toString());
        }
        output.add(solution);
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
                    addSolution();
                // if not proceed to place the rest
                else
                    backtrack(row + 1);
                // backtrack
                removeQueen(row, col);
            }
        }
    }

    public List<List<String>> solveNQueens(int n)
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