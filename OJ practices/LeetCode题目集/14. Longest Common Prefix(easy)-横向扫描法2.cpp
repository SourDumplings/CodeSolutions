/**
 * @file 14. Longest Common Prefix(easy)-横向扫描法2.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-23
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 简单横向扫描，复杂度：
 * 时间 O(mn) 空间 O(m)
 * 
 */

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        string res = strs.front();
        int l = res.length();
        int n = strs.size();
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < l; ++j)
            {
                if (res[j] != strs[i][j])
                {
                    l = j;
                    break;
                }
            }
        }
        return res.substr(0, l);
    }
};