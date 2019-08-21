/*
 * @Author: SourDumplings
 * @Date: 2019-08-21 21:10:14
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/contains-duplicate-ii/
 */

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        map<int, int> mI; // 记录每一个数的上一个数的位置
        int n = nums.size();
        const int MAXD = k + 1;
        for (int i = 0; i < n; i++)
        {
            int num = nums[i];
            if (mI.find(num) != mI.end())
            {
                if (i - mI[num] <= k)
                {
                    return true;
                }
            }
            mI[num] = i;
        }
        return false;
    }
};
