/*
 @Date    : 2018-01-26 15:24:03
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/roman-to-integer/description/
 */

class Solution
{
public:
    int romanToInt(string s)
    {
        array<int, 13> nums{{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1}};
        array<string, 13> romans{{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"}};
        map<string, int> rtoi;
        for (int i = 0; i != 13; ++i)
            rtoi.insert(make_pair(romans[i], nums[i]));
        int result = 0;
        for (int i = 0; i != s.size(); ++i)
        {
            if (i != s.size() - 1 && rtoi.find(s.substr(i, 2)) != rtoi.end())
            {
                result += rtoi[s.substr(i, 2)];
                ++i;
            }
            else if (rtoi.find(s.substr(i, 1)) != rtoi.end())
                result += rtoi[s.substr(i, 1)];
        }
        return result;
    }
};
