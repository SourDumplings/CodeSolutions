/**
 * @file 70. Climbing Stairs(easy)-动态规划法.cpp
 * @author SourDumplings (changzheng300@foxmail.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-04-14
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 */

class Solution
{
public:
    int climbStairs(int n)
    {
        if (n == 1)
        {
            return 1;
        }
        
        int f[n + 1];
        memset(f, -1, sizeof(f));
        f[0] = 0;
        f[1] = 1;
        f[2] = 2;
        for (int i = 3; i < n + 1; ++i)
        {
            f[i] = f[i - 1] + f[i - 2];
        }
        return f[n];
    }
};