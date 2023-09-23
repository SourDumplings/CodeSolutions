/*
 * @Author: SourDumplings
 * @Date: 2023-09-23 11:29:23
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/largest-triangle-area/
 *
 * 易推出三角形面积 S=(1/2)*abs(x1y2+x2y3+x3y1-x1y3-x2y1-x3y2)
 */

class Solution
{
public:
    double largestTriangleArea(vector<vector<int>> &points)
    {
        double res = 0.0;
        size_t n = points.size();
        for (size_t i = 0; i < n; ++i)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            for (size_t j = i + 1; j < n; ++j)
            {
                int x2 = points[j][0];
                int y2 = points[j][1];
                for (size_t k = j + 1; k < n; ++k)
                {
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    double S = calcArea(x1, y1, x2, y2, x3, y3);
                    if (res < S)
                    {
                        res = S;
                    }
                }
            }
        }
        return res;
    }

private:
    double calcArea(int x1, int y1, int x2, int y2, int x3, int y3)
    {
        return abs(x1 * y2 + x2 * y3 + x3 * y1 - x1 * y3 - x2 * y1 - x3 * y2) * 0.5;
    }
};