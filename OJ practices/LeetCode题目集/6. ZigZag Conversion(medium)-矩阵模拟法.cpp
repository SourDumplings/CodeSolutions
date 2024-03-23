/**
 * @file 6. ZigZag Conversion(medium)-矩阵模拟法.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-23
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 模拟 ZIG 过程，使用变长数组
 * 空间复杂度 O(n)，时间复杂度 O(n)
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
        

        vector<vector<char>> rows(numRows);
        int n = s.length();
        bool downward = true;
        int r = -1;
        for (int i = 0; i < n; i++)
        {
            if (downward)
            {
                ++r;
                if (r == numRows - 1)
                {
                    downward = false;
                }
            }
            else
            {
                --r;
                if (r == 0)
                {
                    downward = true;
                }
            }
            rows[r].push_back(s[i]);
        }
        string res;
        for (const vector<char> &row : rows)
        {
            for (char c : row)
            {
                res += c;
            }
        }
        return res;
    }
};