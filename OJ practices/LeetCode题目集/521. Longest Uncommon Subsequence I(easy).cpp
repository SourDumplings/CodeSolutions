/*
 * @Author: SourDumplings
 * @Date: 2019-09-29 17:53:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-uncommon-subsequence-i/
 * 
 * 只需要逐个判断字符串是否相等，都相等则返回-1，不相等就返回较长的字符串即可
 */

class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        int la = a.length(), lb = b.length();
        if (a == b)
        {
            return -1;
        }
        else
        {
            return la < lb ? lb : la;
        }
    }
};