/*
 * @Autor: SourDumplings
 * @Date: 2019-09-17 13:36:47
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/guess-number-higher-or-lower/
 */

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution
{
public:
    int guessNumber(int n)
    {
        unsigned lo = 1, hi = n;
        while (lo <= hi)
        {
            unsigned mi = (lo + hi) / 2;
            unsigned r = guess(mi);
            if (r == 0)
            {
                return mi;
            }
            else if (r == 1)
            {
                lo = mi + 1;
            }
            else
            {
                hi = mi;
            }
        }
        return -1;
    }
};