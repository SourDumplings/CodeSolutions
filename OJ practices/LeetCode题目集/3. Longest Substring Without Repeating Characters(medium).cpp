/*
 * @Autor: SourDumplings
 * @Date: 2019-12-09 14:39:37
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        string thisStr;
        int res = 0;
        for (auto &&c : s)
        {
            auto lastOccur = find(thisStr.begin(), thisStr.end(), c);
            if (lastOccur != thisStr.end())
            {
                if (thisStr.length() > res)
                {
                    res = thisStr.length();
                }
                thisStr.erase(thisStr.begin(), lastOccur + 1);
            }
            thisStr.push_back(c);
        }
        if (thisStr.length() > res)
        {
            res = thisStr.length();
        }
        return res;
    }
};