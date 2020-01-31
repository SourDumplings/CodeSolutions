/*
 * @Author: SourDumplings
 * @Date: 2019-09-17 13:56:47
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/guess-number-higher-or-lower/
 */

/* The guess API is defined in the parent class GuessGame.
  @param num, your guess
  @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
     int guess(int num); */

public class Solution extends GuessGame
{
    public int guessNumber(int n)
    {
        int lo = 1, hi = n;
        while (lo <= hi)
        {
            int mi = (hi - lo) / 2 + lo; // 如果用(hi + lo) / 2会超时
            int r = guess(mi);
            if (r == 0)
            {
                return mi;
            }
            else if (r < 0)
            {
                hi = mi;
            }
            else
            {
                lo = mi + 1;
            }
        }
        return -1;
    }
}