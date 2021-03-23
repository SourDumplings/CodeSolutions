/*
 * @Author: SourDumplings
 * @Date: 2021-03-23 10:19:17
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/maximum-product-of-word-lengths/
 */

class Solution
{
public:
    int maxProduct(vector<string> &words)
    {
        int n = words.size();
        int letters[n];
        int length[n];
        int mask[26];
        mask[0] = 1;
        for (int k = 1; k < 26; ++k)
        {
            mask[k] = (mask[k - 1] << 1);
        }
        sort(words.begin(), words.end(), [](const string &s1, const string &s2)
        {
            return s1.length() > s2.length();
        });
        for (int i = 0; i < n; ++i)
        {
            letters[i] = 0;
            int l = words[i].length();
            length[i] = l;
            for (int j = 0; j < l; ++j)
            {
                char c = words[i][j];
                letters[i] |= mask[c - 'a'];
            }
        }
        int res = 0;
        for (int m = 0; m < n; ++m)
        {
            const string &word1 = words[m];
            for (int i = m + 1; i < n; ++i)
            {
                const string &word2 = words[i];
                if ((letters[m] & letters[i]) == 0)
                {
                    if (length[m] * length[i] > res)
                    {
                        res = length[m] * length[i];
                    }
                    break;
                }
            }
        }
        return res;
    }
};