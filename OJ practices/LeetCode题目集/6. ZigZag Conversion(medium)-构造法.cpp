/**
 * @file 6. ZigZag Conversion(medium)-构造法.cpp
 * @author chadchang (chadchang@tencent.com)
 * @brief 
 * @version 1.0.0
 * @date 2024-03-23
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 按照元素重排列后的特征重新构造，如下，t 为一个周期的元素数
0             0+t                    0+2t                     0+3t
1      t-1    1+t            0+2t-1  1+2t            0+3t-1   1+3t
2  t-2        2+t  0+2t-2            2+2t  0+3t-2             2+3t  
3             3+t                    3+2t                     3+3t
 * 
 * 复杂度：时间 O(n) 空间 O(1)，空间复杂度不考虑返回用的字符串
 */

class Solution
{
public:
    string convert(string s, int numRows)
    {
        int n = s.length();
        if (numRows == 1 || n <= numRows)
        {
            return s;
        }

        int t = 2 * numRows - 2;
        string res;
        for (int r = 0; r < numRows; ++r)
        {
            for (int tIdx = 0; tIdx < n / t + 1; ++tIdx)
            {
                if (n <= tIdx * t + r)
                {
                    break;
                }

                res += s[tIdx * t + r];
                if (0 < r
                    && r < numRows - 1
                    && (tIdx + 1) * t - r < n
                )
                {
                    res += s[(tIdx + 1) * t - r];
                }
            }
        }

        return res;
    }
};