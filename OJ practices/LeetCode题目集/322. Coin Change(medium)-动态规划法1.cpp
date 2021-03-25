/*
 * @Author: SourDumplings
 * @Date: 2021-03-25 10:28:54
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/coin-change/
 */

class Solution
{
private:
    vector<int> f;
    
    int dp(const vector<int> &coins, int resAmount)
    {
        if (resAmount < 0)
        {
            return -1;
        }
        else if (resAmount == 0)
        {
            return 0;
        }
        else if (f[resAmount] != 0)
        {
            return f[resAmount];
        }
        else
        {
            int minCoinNum = INT32_MAX;
            for (int coin : coins)
            {
                int res = dp(coins, resAmount - coin);
                if (res >= 0 && res < minCoinNum)
                {
                    minCoinNum = res + 1;
                }
            }
            f[resAmount] = minCoinNum == INT32_MAX ? -1 : minCoinNum;
            return f[resAmount];
        }
    }
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount < 1)
        {
            return 0;
        }
        f.resize(amount + 1);
        fill(f.begin(), f.end(), 0);
        return dp(coins, amount);
    }
};