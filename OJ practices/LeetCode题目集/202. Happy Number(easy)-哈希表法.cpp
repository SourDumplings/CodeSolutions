/**
 * @file 202. Happy Number(easy)-哈希表法.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * https://leetcode.cn/problems/happy-number/solutions/224894/kuai-le-shu-by-leetcode-solution/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    bool isHappy(int n)
    {
        if (n == 1)
        {
            return true;
        }
        else if (m_set.find(n) != m_set.end())
        {
            return false;
        }
        
        m_set.insert(n);
        int sum = 0;
        while (0 < n)
        {
            int r = n % 10;
            n /= 10;
            sum += r * r;
        }
        return isHappy(sum);
    }

private:
    unordered_set<int> m_set;
};