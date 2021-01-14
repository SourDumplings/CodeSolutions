/*
 * @Author: SourDumplings
 * @Date: 2021-01-14 11:54:02
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 * 
 * 时间复杂度 O(nlogn)， 空间复杂度 O(1)
 * 参考：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2/
 */

class Solution
{
private:
    bool
    do_search(vector<vector<int>> &matrix,
              int rb,
              int cb,
              int re,
              int ce,
              int target)
    {
        if (re <= rb || ce <= cb || target < matrix[rb][cb]
            || matrix[re - 1][ce - 1] < target)
        {
            return false;
        }

        // 沿着中线列向下查找
        int mi = (cb + ce) / 2;
        int r = rb;
        while (r < re && matrix[r][mi] <= target)
        {
            // 沿着 mi 列找
            if (matrix[r][mi] == target)
            {
                return true;
            }
            ++r;
        }
        // 找右上角和左下角，target 不可能在左上角和右下角
        return do_search(matrix, rb, mi + 1, r, ce, target) ||
            do_search(matrix, r, cb, re, mi, target);
    }
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size();
        if (m == 0)
        {
            return false;
        }

        int n = matrix[0].size();
        return do_search(matrix, 0, 0, m, n, target);
    }
};