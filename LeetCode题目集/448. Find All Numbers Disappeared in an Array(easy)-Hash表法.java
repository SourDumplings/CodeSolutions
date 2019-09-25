import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/*
 * @Autor: SourDumplings
 * @Date: 2019-09-25 22:43:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 *
 * 利用哈希表，时间和空间复杂度O(n)
 */

class Solution
{
    public List<Integer> findDisappearedNumbers(int[] nums)
    {
        List<Integer> res = new ArrayList<>();
        int n = nums.length;
        boolean[] h = new boolean[n];
        Arrays.fill(h, false);
        for (int i : nums)
        {
            h[i - 1] = true;
        }
        for (int i = 0; i < n; i++)
        {
            if (!h[i])
            {
                res.add(i + 1);
            }
        }
        return res;
    }
}
