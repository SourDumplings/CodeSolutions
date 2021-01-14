/*
 * @Author: SourDumplings
 * @Date: 2021-01-14 13:06:44
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 * 
 * 时间复杂度 O(m + n)， 空间复杂度 O(1)
 * 参考：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2/
 */

class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
        {
            return false;
        }

        int n = matrix[0].size();
        
        int r = m - 1;
        int c = 0;
        while (r >= 0 && c < n)
        {
            if (matrix[r][c] < target)
            {
                ++c;
            }
            else if (target < matrix[r][c])
            {
                --r;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};