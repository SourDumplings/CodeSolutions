/*
 * @Author: SourDumplings
 * @Date: 2021-03-25 12:30:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/coin-change/
 */

class Solution
{
private:
    vector<int> res;

public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount < 1)
        {
            return 0;
        }
        res.resize(amount + 1);
        const int maxNum = INT32_MAX / 2;
        fill(res.begin(), res.end(), maxNum);
        res[0] = 0;
        int n = coins.size();
        for (int i = 1; i <= amount; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (coins[j] <= i)
                {
                    res[i] = min(res[i], res[i - coins[j]] + 1);
                }
            }
        }
        return res[amount] >= maxNum ? -1 : res[amount];
    }
};