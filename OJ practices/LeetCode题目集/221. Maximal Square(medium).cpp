/*
 * @Author: SourDumplings
 * @Date: 2021-01-03 09:16:53
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/maximal-square/
 * 
 * 
采用动态规划法，dp(i, j) 值的是以 (i, j) 为右下角的正方形的最大边长

如果该位置的值是 00，则 dp(i, j) = 0dp(i,j)=0，因为当前位置不可能在由 11 组成的正方形中；

如果该位置的值是 11，则 dp(i, j)dp(i,j) 的值由其上方、左方和左上方的三个相邻位置的 dpdp 值决定。具体而言，当前位置的元素值等于三个相邻位置的元素中的最小值加 11，状态转移方程如下：

dp(i, j)=min(dp(i−1, j), dp(i−1, j−1), dp(i, j−1))+1

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/maximal-square/solution/zui-da-zheng-fang-xing-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        if (m == 0)
        {
            return 0;
        }
        int n = matrix[0].size();
        int dp[m][n];
        int res = 0;
        for (int k = 0; k < m; ++k)
        {
            for (int i = 0; i < n; ++i)
            {
                if (matrix[k][i] == '1')
                {
                    if (k == 0 || i == 0)
                    {
                        dp[k][i] = 1;
                    }
                    else
                    {
                        int a = 0, b = 0, c = 0;
                        if (k > 0)
                        {
                            a = dp[k - 1][i];
                            if (i > 0)
                            {
                                b = dp[k - 1][i - 1];
                            }
                        }
                        if (i > 0)
                        {
                            c = dp[k][i - 1];
                        }
                        int temp[3]{a, b, c};
                        dp[k][i] = *min_element(temp, temp + 3) + 1;
                    }
                }
                else
                {
                    dp[k][i] = 0;
                }
                if (dp[k][i] > res)
                {
                    res = dp[k][i];
                }
            }
        }
        return res * res;
    }
};