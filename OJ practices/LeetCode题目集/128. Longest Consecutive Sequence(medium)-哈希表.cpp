/*
 * @Author: SourDumplings
 * @Date: 2022-12-08 19:42:55
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.cn/problems/longest-consecutive-sequence/
 * 
 * 思路就是先用哈希表作为集合存下所有的数，然后再遍历
 * 对于每个数 i，先设置下界 down = i, 如果 down - 1 在集合中，就从集合中删掉 down - 1，再更新 down = down - 1
 * 直到 down - 1 不在集合中为止，上界类似
 */


#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty())
        {
            return 0;
        }
        

        unordered_set<int> s(nums.begin(), nums.end());
        int res = 1;
        for (int i : nums)
        {
            int down = i;
            int up = i;
            while (s.find(down - 1) != s.end())
            {
                s.erase(--down);
            }
            while (s.find(up + 1) != s.end())
            {
                s.erase(++up);
            }
            res = max(res, up - down + 1);
        }
        return res;
    }
};