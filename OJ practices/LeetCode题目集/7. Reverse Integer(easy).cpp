/*
 @Date    : 2018-01-06 13:26:27
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/reverse-integer/description/
 */

class Solution
{
public:
    int reverse(int x)
    {
        string s = to_string(x);
        std::reverse(s.begin(), s.end());
        long long i = stoll(s);
        if ( i > 2147483647 || i < -2147483648)
            return 0;
        if (x < 0)
            return -i;
        return i;
    }
};
