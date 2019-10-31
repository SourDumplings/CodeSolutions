/*
 * @Autor: SourDumplings
 * @Date: 2019-10-31 08:57:09
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/find-smallest-letter-greater-than-target/
 */

class Solution
{
    public char nextGreatestLetter(char[] letters, char target)
    {
        int lo = 0;
        int hi = letters.length - 1;
        if (letters[hi] <= target)
        {
            return letters[lo];
        }
        while (lo < hi)
        {
            int mi = (lo + hi) / 2;
            if (target < letters[mi])
            {
                hi = mi;
            }
            else if (letters[mi] <= target)
            {
                lo = mi + 1;
            }
        }
        return letters[lo];
    }
}