/*
 * @Author: SourDumplings
 * @Date: 2021-02-01 10:22:09
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/additive-number/
 */

class Solution
{
private:
    bool dfs(const string &num, int n, int nowIdx, long preTwoSum, long preNum, int seqNum)
    {
        if (nowIdx == n)
        {
            return seqNum > 2;
        }
        for (int i = nowIdx + 1; i <= n; ++i)
        {
            long long thisNum = get_num(num, nowIdx, i);
            if (thisNum == -1)
            {
                continue;
            }
            else if (seqNum >= 2 && thisNum != preTwoSum)
            {
                continue;
            }
            else if (dfs(num, n, i, preNum + thisNum, thisNum, seqNum + 1))
            {
                return true;
            }
        }
        return false;
    }

    long long get_num(const string &num, int b, int e)
    {
        if (b < e - 1 && num[b] == '0'  || b < e - 11)
        {
            return -1;
        }
        long res = 0;
        while (b < e)
        {
            res = res * 10 + num[b++] - '0';
        }
        return res;
    }

public:
    bool isAdditiveNumber(string num)
    {
        return dfs(num, num.length(), 0, 0, 0, 0);
    }
};