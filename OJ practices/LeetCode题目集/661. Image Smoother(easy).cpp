/*
 * @Autor: SourDumplings
 * @Date: 2019-10-12 17:23:31
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/image-smoother/
 */

class Solution
{
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M)
    {
        int r = M.size();
        int c = M[0].size();
        vector<vector<int>> res;
        res.resize(r);
        for (int i = 0; i < r; i++)
        {
            res[i].resize(c);
            for (int j = 0; j < c; j++)
            {
                int count = 0, sum = 0;
                for (int nr = i - 1; nr <= i + 1; nr++)
                {
                    for (int nc = j - 1; nc <= j + 1; nc++)
                    {
                        if (0 <= nr && nr < r && 0 <= nc && nc < c)
                        {
                            sum += M[nr][nc];
                            ++count;
                        }
                    }
                }
                res[i][j] = sum / count;
            }
        }
        return std::move(res);
    }
};