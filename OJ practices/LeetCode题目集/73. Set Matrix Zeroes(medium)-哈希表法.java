import java.util.HashSet;
import java.util.Set;

/*
 * @Author: SourDumplings
 * @Date: 2020-07-13 20:35:37
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: 
 */ 

class Solution {
    public void setZeroes(int[][] matrix)
    {
        Set<Integer> zeroRows = new HashSet<>();
        Set<Integer> zeroCols = new HashSet<>();
        int m = matrix.length;
        int n = matrix[0].length;
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (matrix[i][j] == 0) 
                {
                    zeroRows.add(i);
                    zeroCols.add(j);
                }
            }
        }
        for (Integer c : zeroCols) 
        {
            for (int r = 0; r < m; r++) 
            {
                matrix[r][c] = 0;
            }
        }
        for (Integer r : zeroRows) 
        {
            for (int c = 0; c < n; c++) 
            {
                matrix[r][c] = 0;
            }
        }
    }
}