/*
 * @Author: SourDumplings
 * @Date: 2019-11-15 08:21:22
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/rotate-string/
 * 
 * 用拼接代替 shift
 */

class Solution
{
    public boolean rotateString(String A, String B)
    {
        StringBuilder sb = new StringBuilder(A).append(A);
        return A.length() == B.length() && sb.toString().contains(B);
    }
}