/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/excel-sheet-column-title/
 * @Date: 2019-04-22 22:26:41
 */

class Solution
{
    static const int MAX = 1000;

public:
    string convertToTitle(int n)
    {
        string res;
        char d;
        while (n)
        {
            n -= 1;
            d = n % 26 + 'A';
            res = d + res;
            n /= 26;
        }
        return ret;
    }
};