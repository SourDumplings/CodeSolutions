/*
 * @Author: SourDumplings
 * @Date: 2019-08-20 20:47:30
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/contains-duplicate/
 */

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        set<int> s;
        for (auto &&i : nums)
        {
            if (s.find(i) != s.end())
            {
                return true;
            }
            s.insert(i);
        }
        return false;
    }
};
