/*
 @Date    : 2019-01-23 21:04:44
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/length-of-last-word/
 */

class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        istringstream is(s);
        string str;
        while (is >> str);
        return str.length();
    }
};
