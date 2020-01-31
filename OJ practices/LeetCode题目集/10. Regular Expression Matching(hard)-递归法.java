/*
 * @Author: SourDumplings
 * @Date: 2020-01-10 20:31:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/regular-expression-matching/
 */

class Solution
{
    public boolean isMatch(String s, String p)
    {
        // 如果 p 为空，当且仅当 s 也为空才能匹配成功
        if (p.isEmpty())
            return s.isEmpty();

        // s 和 p 的第一个字符匹配
        boolean first_match = (!s.isEmpty() && (p.charAt(0) == s.charAt(0) || p.charAt(0) == '.'));

        if (p.length() >= 2 && p.charAt(1) == '*')
        {
            // 如果 p 的第二个字符是*
            // 要么跳过前两个字符，从 p 的第三个字符开始匹配 s，如："ab" 和 "c*ab"
            // 要么如果第一个字符是匹配的，那么从 s 的第二个字符开始被 p 匹配，如 "aaab" 和 "a*b"
            return (isMatch(s, p.substring(2)) || (first_match && isMatch(s.substring(1), p)));
        }
        else
        {
            // 如果第二个字符不是*，那么必须要求第一个字符匹配
            // 然后各自从第二个字符匹配即可
            return first_match && isMatch(s.substring(1), p.substring(1));
        }
    }
}
