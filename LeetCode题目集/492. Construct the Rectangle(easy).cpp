/*
 * @Autor: SourDumplings
 * @Date: 2019-09-27 15:19:01
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/construct-the-rectangle/
 */

class Solution
{
public:
    vector<int> constructRectangle(int area)
    {
        int max = sqrt(area);
        vector<int> res;
        for (int w = max; w >= 0; --w)
        {
            if (area % w == 0)
            {
                int l = area / w;
                res.push_back(l);
                res.push_back(w);
                break;
            }
        }
        return res;
    }
};