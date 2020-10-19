/*
 * @Author: SourDumplings
 * @Date: 2020-10-19 19:23:36
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/word-break/
 */

class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        int l = s.length();
        bool dp[l + 1];
        fill(dp, dp + l + 1, false);
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        dp[0] = true;
        for (int i = 1; i < l + 1; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && (dict.find(s.substr(j, i - j)) != dict.end()))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[l];
    }
};