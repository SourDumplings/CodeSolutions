/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/single-number/
 * @Date: 2019-03-31 19:11:50
 */

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        unordered_map<int, int> map;
        int ret;
        for (auto &i : nums)
        {
            ++map[i];
        }
        for (auto &i : nums)
        {
            if (map[i] == 1)
            {
                ret = i;
                break;
            }
        }
        return ret;
    }
};