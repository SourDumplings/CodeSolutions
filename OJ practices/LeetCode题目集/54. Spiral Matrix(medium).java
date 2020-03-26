import java.util.ArrayList;
import java.util.List;

/*
 * @Author: SourDumplings
 * @Date: 2020-03-17 21:36:09
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/spiral-matrix/
 */

class Solution
{
    public List<Integer> spiralOrder(int[][] matrix)
    {
        List<Integer> res = new ArrayList<>();
        int m = matrix.length;
        if (m == 0)
        {
            return res;
        }
        int n = matrix[0].length;
        int[] limits = new int[]
        { n - 1, m - 1, 0, 0 };
        int size = m * n;
        int direction = 0;
        int i = 0, j = 0;
        for (int count = 0; count < size; ++count)
        {
            res.add(matrix[i][j]);
            switch (direction)
            {
            case 0:
            {
                // right
                if (j == limits[direction])
                {
                    ++limits[(direction + 3) % 4];
                    direction = (direction + 1) % 4;
                    ++i;
                }
                else
                {
                    ++j;
                }
                break;
            }
            case 1:
            {
                // down
                if (i == limits[direction])
                {
                    --limits[(direction + 3) % 4];
                    direction = (direction + 1) % 4;
                    --j;
                }
                else
                {
                    ++i;
                }
                break;
            }
            case 2:
            {
                // left
                if (j == limits[direction])
                {
                    --limits[(direction + 3) % 4];
                    direction = (direction + 1) % 4;
                    --i;
                }
                else
                {
                    --j;
                }
                break;
            }
            case 3:
            {
                // up
                if (i == limits[direction])
                {
                    ++limits[(direction + 3) % 4];
                    direction = (direction + 1) % 4;
                    ++j;
                }
                else
                {
                    --i;
                }
                break;
            }
            }
        }
        return res;
    }
}