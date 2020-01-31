/*
 * @Author: SourDumplings
 * @Date: 2019-10-09 20:10:00
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/can-place-flowers/
 */

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int numOfZero = count(flowerbed.begin(), flowerbed.end(), 0);
        if (numOfZero < n - 1)
        {
            return false;
        }
        int l = flowerbed.size();
        for (int i = 0; i < l; ++i)
        {
            if (n == 0)
            {
                return true;
            }

            if (flowerbed[i] == 0 &&
                (i > 0 && flowerbed[i - 1] != 1 || i == 0) &&
                (i < l - 1 && flowerbed[i + 1] != 1 || i == l - 1))
            {
                flowerbed[i] = 1;
                --n;
            }
        }
        return n == 0;
    }
};