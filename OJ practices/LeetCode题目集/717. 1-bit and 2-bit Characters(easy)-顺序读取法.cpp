/*
 * @Autor: SourDumplings
 * @Date: 2019-10-28 10:45:09
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/1-bit-and-2-bit-characters/
 * 
 * 顺序逐个读取，如果遇到0则指针前进1位，遇到1则指针前进两位
 * 最后判断指针是否在最后一位即可
 */

class Solution
{
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        int i = 0;
        int n = bits.size();
        while (i < n - 1)
        {
            i += bits[i] + 1;
        }
        return i == n - 1;
    }
};