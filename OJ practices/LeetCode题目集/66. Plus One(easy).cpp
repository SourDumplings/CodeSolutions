/*
 @Date    : 2019-01-24 20:16:23
 @Author  : 酸饺子 (changzheng300@foxmail.com)
 @Link    : https://github.com/SourDumplings
 @Version : $Id$
*/

/*
https://leetcode.com/problems/plus-one/
 */

class Solution
{
public:
    vector<int> plusOne(vector<int>& digits)
    {
        do_add(digits, digits.size() - 1);
        return digits;
    }

    void do_add(vector<int>& num, int d)
    {
        if (d == -1)
        {
            num.insert(num.begin(), 1);
            return;
        }
        if (num[d] == 9)
        {
            num[d] = 0;
            do_add(num, d - 1);
        }
        else
            ++num[d];
        return;
    }
};
