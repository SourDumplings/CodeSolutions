/*
 * @Author: SourDumplings
 * @Date: 2019-09-10 20:32:57
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/power-of-three/
 * 
 * 设3^i = n，则i = log3(n) = log10(n) / log10(3)
 * 判断这样得到的3^i还是不是n，或者i是不是整数即可（用 % 1判断）
 */

class Solution
{
    public boolean isPowerOfThree(int n)
    {
        return n != 0 && (Math.log10(n) / Math.log10(3)) % 1 == 0;
    }
}