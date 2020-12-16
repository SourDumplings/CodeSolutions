/*
 * @Author: SourDumplings
 * @Date: 2020-12-16 09:31:53
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/largest-number/
 */

class Solution
{
public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), [this] (int num1, int num2)
        {
            string s1 = to_string(num1);
            string s2 = to_string(num2);
            return cmp(s1, s2);
        });
        string res;
        for (int num : nums)
        {
            res += to_string(num);
        }
        int l = res.length();
        bool isZero = true;
        for (int i = 0; i < l; ++i)
        {
            if (res[i] != '0')
            {
                res.erase(0, i);
                isZero = false;
                break;
            }
        }
        if (isZero)
        {
            res = "0";
        }
        return res;
    }

private:
    bool cmp(const string &s1, const string &s2)
    {
        if (s1[0] == s2[0])
        {
            return s1 + s2 > s2 + s1;
        }
        return s1[0] > s2[0];
    }
};