/*
 * @Author: SourDumplings
 * @Date: 2020-07-23 11:03:01
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/search-a-2d-matrix/
 */ 

class Solution 
{
    public boolean searchMatrix(int[][] matrix, int target) 
    {
        int m = matrix.length;
        if (m == 0)
        {
            return false;
        }
        int n = matrix[0].length;
        if (n == 0)
        {
            return false;
        }
        int i = 0, j = m;
        int r = -1;
        while (i < j)
        {
            int mi = (i + j) / 2;
            if (matrix[mi][0] == target)
            {
                return true;
            }
            else if (matrix[mi][0] < target)
            {
                if (mi < m - 1 && matrix[mi + 1][0] > target || mi == m - 1)
                {
                    r = mi;
                    break;
                }
                else
                {
                    i = mi + 1;
                }
            }
            else
            {
                j = mi;
            }
        }
        if (r != -1)
        {
            i = 0;
            j = n;
            while (i < j)
            {
                int mi = (i + j) / 2;
                if (matrix[r][mi] == target)
                {
                    return true;
                }
                else if (matrix[r][mi] < target)
                {
                    i = mi + 1;
                }
                else 
                {
                    j = mi;
                }
            }
        }
        return false;
    }
}