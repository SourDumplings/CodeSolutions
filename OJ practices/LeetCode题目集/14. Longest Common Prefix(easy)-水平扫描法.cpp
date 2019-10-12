/*
 @Date    : 2019-01-06 22:47:42
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/longest-common-prefix/
 */

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        if (strs.empty())
        {
            return "";
        }
        string prefix = strs[0];
        for (int i = 1; i < strs.size(); ++i)
        {
            while (strs[i].find(prefix) != 0)
            {
                prefix = prefix.substr(0, prefix.length() - 1);
            }
            if (prefix.empty())
            {
                return "";
            }
        }
        return prefix;
    }
};
