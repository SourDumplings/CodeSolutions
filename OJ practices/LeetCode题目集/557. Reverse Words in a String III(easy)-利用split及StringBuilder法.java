/*
 * @Author: SourDumplings
 * @Date: 2019-10-04 15:22:45
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/reverse-words-in-a-string-iii/
 */

class Solution
{
    public String reverseWords(String s)
    {
        String[] ss = s.split(" ");
        StringBuilder res = new StringBuilder();
        int output = 0;
        for (String word : ss)
        {
            StringBuilder sb = new StringBuilder(word);
            if (output++ != 0)
            {
                res.append(' ');
            }
            res.append(sb.reverse());
        }
        return res.toString();
    }
}