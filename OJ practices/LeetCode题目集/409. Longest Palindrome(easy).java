import java.util.Arrays;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-23 15:55:05
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-palindrome/
 */

class Solution
{
    public int longestPalindrome(String s)
    {
        int[] A = new int[200];
        int l = s.length();
        Arrays.fill(A, 0);
        for (int i = 0; i < l; i++)
        {
            ++A[s.charAt(i) - 'A'];
        }
        int res = 0;
        boolean isFirstOdd = true;
        for (int i = 0; i < 200; i++)
        {
            if ((A[i] & 1) == 1)
            {
                if (isFirstOdd)
                {
                    res += A[i];
                    isFirstOdd = false;
                }
                else
                {
                    res += A[i] - 1;
                }
            }
            else
            {
                res += A[i];
            }
        }
        return res;
    }
}