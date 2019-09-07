/*
 * @Author: SourDumplings
 * @Date: 2019-09-07 20:51:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/nim-game/
 * 
 * 策略就是抢4，为了抢4就抢8，以此类推，即只要抢到4的倍数时候让对方出就稳赢。
 * 所以只要n不是4的倍数就稳赢
 */

class Solution
{
public:
    bool canWinNim(int n)
    {
        return n % 4 != 0;
    }
};