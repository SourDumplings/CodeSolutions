/*
 * @Author: SourDumplings
 * @Date: 2019-09-23 15:17:44
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-palindrome/
 * 
 * 回文序列中奇数个数的元素只能最多有一个
 */

class Solution
{
public:
    int longestPalindrome(string s)
    {
        int A[200];
        fill(A, A + 200, 0);
        for (auto &&c : s)
        {
            ++A[c - 'A'];
        }
        bool isFirstOdd = true;
        int res = 0;
        for (int i = 0; i < 200; i++)
        {
            if (A[i] & 1)
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
};
