/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/single-number/
 * @Date: 2019-03-31 19:11:50
 * 
 * 将所有的数放在集合里，求和再2倍，再减去原序列和即可
 */

class Solution
{
  public:
    int singleNumber(vector<int> &nums)
    {
        set<int> s;
        for (auto &i : nums)
        {
            s.insert(i);
        }
        int temp = accumulate(s.begin(), s.end(), 0) * 2;
        return temp - accumulate(nums.begin(), nums.end(), 0);
    }
};