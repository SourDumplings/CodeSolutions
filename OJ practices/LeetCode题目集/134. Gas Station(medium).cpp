/**
 * @file 134. Gas Station(medium).cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 加油站-加加减减的前进问题，很典型
 * @version 1.0.0
 * @date 2024-03-22
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 核心是如果x到达不了y+1，那么 x-y 之间的点也不可能到达y+1，
 * 因为中间任何一点的油都是拥有前面的余量的，所以下次遍历直接从y+1开始
 * https://leetcode.cn/problems/gas-station/solutions/488357/jia-you-zhan-by-leetcode-solution/?envType=study-plan-v2&envId=top-interview-150
 * 
 * 复杂度：时间 O(n) 空间 O(1)
 */

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int n = gas.size();
        int start = 0;
        int count = 0;
        while (count < n)
        {
            int thisStart = start;
            int resGas = gas[thisStart];
            while (true)
            {
                resGas -= cost[thisStart];
                ++count;
                int nextStation = (thisStart + 1) % n;
                if (resGas < 0)
                {
                    start = nextStation;
                    break;
                }
                thisStart = nextStation;
                if (thisStart == start)
                {
                    return start;
                }
                
                resGas += gas[thisStart];
            }
        }
        return -1;
    }
};