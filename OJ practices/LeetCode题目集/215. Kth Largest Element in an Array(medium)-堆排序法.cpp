/*
 * @Author: SourDumplings
 * @Date: 2020-12-30 18:38:55
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/kth-largest-element-in-an-array/
 * 
 * 时间复杂度为 O(n + klogn)，空间复杂度为 O(1)
 */

class Solution
{
private:
    void perc_down(vector<int> &nums, int f, int n)
    {
        int x = nums[f];
        int p, c;
        for (p = f; p * 2 + 1 < n; p = c)
        {
            c = p * 2 + 1;
            if (c + 1 < n && nums[c] < nums[c + 1])
            {
                c++;
            }
            if (x < nums[c])
            {
                nums[p] = nums[c];
            }
            else
            {
                break;
            }
        }
        nums[p] = x;
    }
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        int n = nums.size();
        int res = 0;
        for (int i = (n - 1) / 2; i >= 0; --i)
        {
            perc_down(nums, i, n);
        }
        for (int j = 0; j < k; ++j)
        {
            if (j == k - 1)
            {
                res = nums[0];
                break;
            }
            nums[0] = nums[--n];
            perc_down(nums, 0, n);
        }
        return res;
    }
};