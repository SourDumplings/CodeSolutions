/*
 * @Author: SourDumplings
 * @Date: 2020-11-30 22:32:26
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/maximum-product-subarray/
 * 
 * 参考：https://leetcode-cn.com/problems/maximum-product-subarray/solution/cheng-ji-zui-da-zi-shu-zu-by-leetcode-solution/
 * 需要考虑到，这不是简单的一阶的状态转移，因为有负数会导致负负得正
 * 例如对于 {5,6,−3,4,−3}，按照简单的一阶状态转移算法，即：
 * fmax(i) = max{fmax(i − 1) × ai, ai} 
 * 得到的结果会是 30，但正确结果由于负负得正的存在是这五个数的积
 * 考虑当前位置如果是一个负数的话，那么我们希望以它前一个位置结尾的某个段的积也是个负数，
 * 这样就可以负负得正，并且我们希望这个积尽可能「负得更多」，即尽可能小。
 * 如果当前位置是一个正数的话，我们更希望以它前一个位置结尾的某个段的积也是个正数，并且希望它尽可能地大。
 * 因此可以再维护一个 fmin(i)
 * 即有状态转移方程：
 * fmax(i) = max{fmax(i − 1) × ai, ai, fmin(i - 1) × ai} 
 * fmax(i) = min{fmin(i − 1) × ai, ai, fmax(i - 1) × ai}  
 * 由于一阶的特性，故可以用变量代替数组维护 f(i - 1) 对应的值，使得实现空间复杂度 O(1)，时间复杂度 O(n)
 */

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int maxF = nums[0], minF = nums[0], ans = nums[0];
        for (int i = 1; i < nums.size(); ++i)
        {
            int mx = maxF, mn = minF;
            maxF = max(mx * nums[i], max(nums[i], mn * nums[i]));
            minF = min(mn * nums[i], min(nums[i], mx * nums[i]));
            ans = max(maxF, ans);
        }
        return ans;
    }
};