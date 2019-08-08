/*
 * @Author: SourDumplings
 * @Date: 2019-08-08 14:12:19
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/house-robber/
 * 
 * 对于任何一步只有两种可能，要么隔一个房子要么隔两个，如果隔三个那就会等效于两个隔一个偷的钱肯定少
 * 采用简单的动态规划思想，用Record记录从某个房子出发能偷到的最大钱数
 */

class Solution
{
public:
    const static int MAX = 10000;
    int record[MAX];
    int rob(vector<int> &nums)
    {
        fill(record, record + MAX, -1);
        return max(do_rob(0, nums), do_rob(1, nums));
    }
    int do_rob(int s, vector<int> &nums)
    {
        if (record[s] != -1)
        {
            return record[s];
        }
        int n = nums.size();
        int res = 0;
        if (s < n)
        {
            res = nums[s];
            if (s < n - 2)
            {
                int res1 = 0, res2 = 0;
                res1 = do_rob(s + 2, nums);
                res2 = do_rob(s + 3, nums);
                res += max(res1, res2);
            }
        }
        record[s] = res;
        return res;
    }
};