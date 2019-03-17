/*
 @Date    : 2019-01-06 23:25:02
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/longest-common-prefix/solution/
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
        for (int prefixL = 0; prefixL < strs[0].size(); ++prefixL)
        {
            char c = strs[0][prefixL];
            for (int i = 1; i != strs.size(); ++i)
            {
                if (strs[i].length() == prefixL || strs[i][prefixL] != c)
                {
                    return strs[i].substr(0, prefixL);
                }
            }
        }
        return strs[0];
    }
};
