/*
 * @Author: SourDumplings
 * @Date: 2020-12-30 19:16:44
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 * 
 * 参考：https://leetcode-cn.com/problems/kth-largest-element-in-an-array/solution/shu-zu-zhong-de-di-kge-zui-da-yuan-su-by-leetcode-/
 * 结合快速排序，随机选轴点进行划分
 * 每次划分完毕后轴点都会在最终的位置，如果该位置对应的序号正好是 k - 1，则完成
 * 如果序号比 k - 1 小，则划分右半边，否则划分左半边
 * 时间复杂度 O(n)，空间复杂度 O(1)
 */

class Solution
{
private:
    int partition(vector<int> &nums, int b, int e)
    {
        int x = nums[b];
        while (b < e - 1)
        {
            while (b < e - 1 && x >= nums[e - 1])
            {
                --e;
            }
            nums[b] = nums[e - 1];
            while (b < e - 1 && nums[b] >= x)
            {
                ++b;
            }
            nums[e - 1] = nums[b];
        }
        nums[b] = x;
        return b;
    }
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        int m, b = 0, e = n;
        int res = 0;
        while (true)
        {
            m = partition(nums, b, e);
            if (m == k - 1)
            {
                res = nums[m];
                break;
            }
            else if (m < k - 1)
            {
                b = m + 1;
            }
            else
            {
                e = m;
            }
        }
        return res;
    }
};