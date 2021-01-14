/*
 * @Author: SourDumplings
 * @Date: 2021-01-14 10:59:55
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/search-a-2d-matrix-ii/
 * 
 * 时间复杂度 O(log(n!))，空间复杂度 O(1)
 * 参考：https://leetcode-cn.com/problems/search-a-2d-matrix-ii/solution/sou-suo-er-wei-ju-zhen-ii-by-leetcode-2/
 */

class Solution
{
private:
    bool
    do_search(vector<vector<int>> &matrix, int target, int start, bool vertical)
    {
        int lo = start;
        int hi = vertical ? matrix[0].size() : matrix.size(); // 是否是纵向搜索

        while (lo < hi)
        {
            int mi = (lo + hi) / 2;
            if (vertical)
            {
                if (matrix[start][mi] < target)
                {
                    lo = mi + 1;
                }
                else if (matrix[start][mi] > target)
                {
                    hi = mi;
                }
                else
                {
                    return true;
                }
            }
            else
            {
                if (matrix[mi][start] < target)
                {
                    lo = mi + 1;
                }
                else if (matrix[mi][start] > target)
                {
                    hi = mi;
                }
                else
                {
                    return true;
                }
            }
        }
        return false;
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
        int shortDim = min(m, n); // 找到短对角线，沿着对角线进行二分查找横和纵
        for (int i = 0; i < shortDim; ++i)
        {
            bool verticalFound = do_search(matrix, target, i, true);
            bool horizontalFound = do_search(matrix, target, i, false);
            if (verticalFound || horizontalFound)
            {
                return true;
            }
        }
        return false;
    }
};