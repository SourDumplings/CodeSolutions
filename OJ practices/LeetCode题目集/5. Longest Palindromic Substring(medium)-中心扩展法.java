/*
 * @Author: SourDumplings
 * @Date: 2019-12-11 20:04:40
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-palindromic-substring/
 * 
 * 算法思想是逐个扫描作为中心，分两种情况，一种是奇数个元素的子列，一种是偶数个元素的子列
 */

class Solution
{
    public String longestPalindrome(String s)
    {
        if (s == null || s.isEmpty())
        {
            return "";
        }
        int l = s.length();
        String res = s.substring(0, 1);
        int maxL = 0, centor = 0;
        boolean flag = false;
        for (int i = 0; i < l; i++)
        {
            int l1 = tryCenterAt(s, i, 0);
            int l2 = tryCenterBetween(s, i, i + 1, 0);
            if (l1 > l2)
            {
                if (l1 > maxL)
                {
                    flag = false;
                    maxL = l1;
                    centor = i;
                }
            }
            else if (l2 > maxL)
            {
                flag = true;
                maxL = l2;
                centor = i;
            }
        }
        if (flag)
        {
            res = s.substring(centor - maxL / 2 + 1, centor + maxL / 2 + 1);
        }
        else
        {
            res = s.substring(centor - maxL / 2, centor + maxL / 2 + 1);
        }
        return res;
    }

    private int tryCenterAt(String s, int c, int r)
    {
        if (c - r - 1 >= 0 && c + r + 1 < s.length() && s.charAt(c - r - 1) == s.charAt(c + r + 1))
        {
            return tryCenterAt(s, c, r + 1);
        }
        else
        {
            return 2 * r + 1;
        }
    }

    private int tryCenterBetween(String s, int left, int right, int r)
    {
        if (left - r >= 0 && right + r < s.length() && s.charAt(left - r) == s.charAt(right + r))
        {
            return tryCenterBetween(s, left, right, r + 1);
        }
        else
        {
            return 2 * r;
        }
    }
}