import java.util.Arrays;

/*
 * @Autor: SourDumplings
 * @Date: 2019-09-27 09:17:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/heaters/
 */

class Solution
{
    public int findRadius(int[] houses, int[] heaters)
    {
        Arrays.sort(houses);
        Arrays.sort(heaters);
        int minR = 0, thisR;
        int ho = houses.length, he = heaters.length;
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
                thisR = Math.min(heaters[j] - houses[i], houses[i] - heaters[j - 1]);
            }
            if (thisR > minR)
            {
                minR = thisR;
            }
        }

        return minR;
    }
}