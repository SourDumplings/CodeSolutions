/*
 * @Author: SourDumplings
 * @Date: 2021-03-24 09:59:59
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/bulb-switcher/
 * 
 * 对于开着的灯泡即为操作次数为奇数次的灯泡
 * 每个灯泡都会在其因数轮的操作中被操作
 * 例如对于20号灯泡，其会第1、2、4、5、10、20轮被操作
 * 因此最后亮着的一定是完全平方数序号的灯泡，因为只有完全平方数是奇数个因子
 * 完全平方数的个数即为 n 的平方根
 */

class Solution 
{
public:
    int bulbSwitch(int n) 
    {
        return sqrt(n);
    }
};