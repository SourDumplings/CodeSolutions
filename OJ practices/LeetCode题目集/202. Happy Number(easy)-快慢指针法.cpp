/**
 * @file 202. Happy Number(easy)-快慢指针法.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-04-22
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 循环的话一定会成环，用快慢指针一定会相遇
 * 
 * https://leetcode.cn/problems/happy-number/solutions/224894/kuai-le-shu-by-leetcode-solution/?envType=study-plan-v2&envId=top-interview-150
 */

class Solution
{
public:
    bool isHappy(int n)
    {
        int fast = getNext(n);
        int slow = n;
        while (fast != slow && fast != 1)
        {
            slow = getNext(slow);
            fast = getNext(getNext(fast));
        }
        return fast == 1;
    }

private:
    int getNext(int n)
    {
        int sum = 0;
        while (0 < n)
        {
            int r = n % 10;
            n /= 10;
            sum += r * r;
        }
        return sum;
    }
};
