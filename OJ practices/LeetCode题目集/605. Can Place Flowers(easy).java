/*
 * @Author: SourDumplings
 * @Date: 2019-10-09 20:20:55
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/can-place-flowers/
 */

class Solution
{
    public boolean canPlaceFlowers(int[] flowerbed, int n)
    {
        int l = flowerbed.length;
        for (int i = 0; i < l; i++)
        {
            if (n == 0)
            {
                return true;
            }
            if (flowerbed[i] == 0 && (i > 0 && flowerbed[i - 1] == 0 || i == 0)
                    && (i < l - 1 && flowerbed[i + 1] == 0 || i == l - 1))
            {
                flowerbed[i] = 1;
                --n;
            }
        }
        return n == 0;
    }
}