/*
 * @Author: SourDumplings
 * @Date: 2019-09-27 08:21:02
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/heaters/
 */

class Solution
{
public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int minR = 0, thisR;
        int ho = houses.size(), he = heaters.size();
        int j = 0;
        for (int i = 0; i < ho; i++)
        {
            while (j < he && heaters[j] < houses[i])
            {
                ++j;
            }
            if (j == he)
            {
                thisR = houses[i] - heaters[j - 1];
            }
            else if (j == 0)
            {
                thisR = heaters[j] - houses[i];
            }
            else
            {
                thisR = min(heaters[j] - houses[i], houses[i] - heaters[j - 1]);
            }
            if (thisR > minR)
            {
                minR = thisR;
            }
        }

        return minR;
    }
};