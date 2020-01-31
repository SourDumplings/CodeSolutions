/*
 * @Author: SourDumplings
 * @Date: 2019-10-28 11:00:06
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/1-bit-and-2-bit-characters/
 * 
 * 查看倒数第二个元素，数从它开始往前有几个1，看是否有偶数个1即可
 * 看几个例子：
 * 101110 false
 * 1011110 true
 * 11011110 true
 * 10000 true
 * 110100 true
 * 就发现只需要关注倒数第二位元素及往前都是1这一种情况就够了
 */

class Solution
{
    public boolean isOneBitCharacter(int[] bits)
    {
        int l = bits.length;
        int i = l - 2;
        while (i >= 0 && bits[i] == 1)
        {
            --i;
        }
        return (l - i) % 2 == 0;
    }
}