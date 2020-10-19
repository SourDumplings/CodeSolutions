/*
 * @Author: SourDumplings
 * @Date: 2020-10-19 19:10:22
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/word-break/
 */

class Solution
{
    public boolean wordBreak(String s, List<String> wordDict)
    {
        Set<String> set = new HashSet<>(wordDict);
        int l = s.length();
        boolean[] dp = new boolean[l + 1];
        Arrays.fill(dp, false);
        dp[0] = true;
        for (int i = 1; i <= l; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (dp[j] && set.contains(s.substring(j, i)))
                {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[l];
    }
}