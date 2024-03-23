/*
 * @Author: SourDumplings
 * @Date: 2020-01-06 19:54:33
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/zigzag-conversion/
 * 
 * 因为最终结果是按行输出，其实只需要知道下一个字符该放在第几行即可，即不用关心列
 * 实际上就是矩阵模拟法
 */

class Solution
{
public:
    string convert(string s, int numRows)
    {
        if (numRows == 1)
        {
            return s;
        }

        vector<string> a(numRows);
        int r = 0;
        bool moveDown = false;
        for (char c : s)
        {
            a[r] += c;
            if (r == numRows - 1 || r == 0)
            {
                moveDown = !moveDown;
            }
            if (moveDown)
            {
                ++r;
            }
            else
            {
                --r;
            }
        }
        string ret;
        for (auto &&str : a)
        {
            for (auto &&c : str)
            {
                ret += c;
            }
        }
        return ret;
    }
};