/*
 * @Author: SourDumplings
 * @Date: 2021-03-20 10:57:22
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/super-ugly-number/
 */

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        priority_queue<int, vector<int>, greater<int>> q; // C++ 中默认为大顶堆，此处需要小顶堆
        q.push(1);
        int lastNum = 0;
        while (n > 1)
        {
            int uglyNum = q.top();
            q.pop();
            if (uglyNum != lastNum)
            {
                for (int p : primes)
                {
                    long long nextUglyNum = static_cast<long long>(p) * uglyNum;
                    if (nextUglyNum > INT32_MAX)
                    {
                        break;
                    }
                    q.push(nextUglyNum);
                }
                --n;
                lastNum = uglyNum;
            }
        }
        while (lastNum == q.top())
        {
            // 去重
            q.pop();
        }
        return q.top();
    }
};