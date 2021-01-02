/*
 * @Author: SourDumplings
 * @Date: 2021-01-02 11:02:50
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/contains-duplicate-iii/
 * 
 * 参考：https://leetcode-cn.com/problems/contains-duplicate-iii/solution/jian-dan-yi-dong-de-cjie-fa-by-zhu-que-3-4p53/
 */

class Solution
{
public:
    bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int k, int t)
    {
        std::set<long> s;
        for (int i = 0; i < nums.size(); ++i)
        {
            // 看窗口中是否有不小于 nums[i] - t 的元素
            auto pos = s.lower_bound(long(nums[i]) - t);
            // 如果有的话再检查上界
            if (pos != s.end() && *pos <= long(nums[i]) + t)
            {
                return true;
            }
            s.insert(nums[i]);

            if (s.size() > k)
            {
                // 维护滑动窗口大小，里面最多 k 个元素
                // 这样的话只要满足了 t 条件即可
                s.erase(nums[i - k]);
            }
        }
        return false;
    }
};