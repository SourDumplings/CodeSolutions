/*
 * @Autor: SourDumplings
 * @Date: 2019-09-26 07:56:31
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/minimum-moves-to-equal-array-elements/
 *
 * 先保持数组中的最大元素不变，记为max，增长其他元素，使得数组中原本最小的元素min和max相等
 * 所需要增长的次数为max - min，然后这两个元素相等，都成为了当前最小的两个元素，当前最大的元素就是
 * 原数组中第二大的元素max2，保持其不变，增长min使其达到max2，这样又增长了max2 - min次
 * 于是此时就有了至少三个元素是相等的，依次类推，便可知总共需要增长的次数为sum - min - min * (n - 1)
 */

class Solution
{
public:
    int minMoves(vector<int> &nums)
    {
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        int min = *min_element(nums.begin(), nums.end());
        return sum - min * nums.size();
    }
};