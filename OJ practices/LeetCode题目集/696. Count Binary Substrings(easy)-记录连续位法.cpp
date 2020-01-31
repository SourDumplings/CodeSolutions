/*
 * @Author: SourDumplings
 * @Date: 2019-10-20 10:44:02
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/count-binary-substrings/
 * 
 * 使用数组group记录连续位的位数
 * 比如对于s = "110001111000000"，那么groups = [2, 3, 4, 6]
 * 如果对于11000或者00111即group[i - 1] = 2， group[i] = 3
 * 那么我们一定能够得到连续位为2个的子串（1100或者0011）
 * 因此我们统计出min(group[i - 1], group[i])的和即可
 */

class Solution
{
public:
    int countBinarySubstrings(string s)
    {
        int l = s.length();
        int t = 0;
        int group[l];
        fill(group, group + l, 0);
        group[0] = 1;
        for (int i = 1; i < l; i++)
        {
            if (s[i - 1] != s[i])
            {
                group[++t] = 1;
            }
            else
            {
                ++group[t];
            }
        }
        int res = 0;
        for (int i = 1; i <= t; i++)
        {
            res += min(group[i - 1], group[i]);
        }
        return res;
    }
};