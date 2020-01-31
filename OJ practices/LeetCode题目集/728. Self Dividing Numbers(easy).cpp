/*
 * @Author: SourDumplings
 * @Date: 2019-10-30 09:24:49
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/self-dividing-numbers/
 */

class Solution
{
public:
    vector<int> selfDividingNumbers(int left, int right)
    {
        vector<int> res;
        for (int i = left; i <= right; i++)
        {
            if (isOK(i))
            {
                res.push_back(i);
            }
        }
        return res;
    }

    bool isOK(int num)
    {
        int d;
        int temp = num;
        do
        {
            d = temp % 10;
            if (d == 0 || num % d != 0)
            {
                return false;
            }
            temp /= 10;
        } while (temp > 0);
        return true;
    }
};