/*
 * @Author: SourDumplings
 * @Date: 2019-09-23 08:50:45
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/convert-a-number-to-hexadecimal/
 * 
 * 采用位运算法，16进制相当于每四位作为一个数字
 * 将32位数每四位为一组转换为16进制数字即可，与15坐位与再右移4位做8次
 */

class Solution
{
public:
    string toHex(int num)
    {
        if (num == 0)
        {
            return "0";
        }

        int hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a',
                       'b', 'c', 'd', 'e', 'f'};
        string res(8, '0');
        for (int i = 0; i < 8; i++)
        {
            res[7 - i] = hex[num & 15];
            num >>= 4;
        }
        int j = 0;
        while (res[j] == '0')
        {
            ++j;
        }
        return res.substr(j);
    }
};
