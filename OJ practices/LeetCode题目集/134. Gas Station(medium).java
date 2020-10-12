/*
 * @Author: SourDumplings
 * @Date: 2020-10-12 19:40:33
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/gas-station/
 */

class Solution
{
    public int canCompleteCircuit(int[] gas, int[] cost)
    {
        int n = gas.length;
        for (int i = 0; i < n; i++)
        {
            if (cost[i] <= gas[i])
            {
                int count = 1;
                int resGas = gas[i];
                int pos = i;
                while (count < n + 1)
                {
                    resGas -= cost[pos];
                    if (resGas < 0)
                    {
                        break;
                    }
                    pos = (pos + 1) % n;
                    ++count;
                    resGas += gas[pos];
                }
                if (count == n + 1)
                {
                    return i;
                }
            }
        }
        return -1;
    }
}