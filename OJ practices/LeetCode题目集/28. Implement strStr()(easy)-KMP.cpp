/**
 * @file 28. Implement strStr()(easy)-KMP.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-24
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * KMP 算法，详见：【有道云笔记】KMP 算法.md
https://note.youdao.com/s/CbxxkS1Q

复杂度：时间 O(n + m)，空间 O(n)
 */

class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int i = 0, j = 0;
        int nh = haystack.size();
        int nn = needle.size();
        int next[nn];
        getNext(next, needle);
        while (i < nh && j < nn)
        {
            if (j == -1 || haystack[i] == needle[j])
            {
                ++i;
                ++j;
            }
            else
            {
                j = next[j];
            }
        }
        if (j == nn)
        {
            return i - nn;
        }
        return -1;
    }

private:
    void getNext(int next[], const string &needle)
    {
        int n = needle.size();
        int i = 0, j = -1;
        next[0] = -1;
        while (true)
        {
            if (j == -1 || needle[i] == needle[j])
            {
                ++i;
                if (i == n)
                {
                    break;
                }
                ++j;
                next[i] = j;
            }
            else
            {
                j = next[j];
            }
        }
    }
};