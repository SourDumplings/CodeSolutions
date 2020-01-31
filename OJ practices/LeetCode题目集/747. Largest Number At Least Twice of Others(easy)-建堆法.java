import java.util.HashMap;
import java.util.Map;
import java.util.PriorityQueue;

/*
 * @Author: SourDumplings
 * @Date: 2019-11-03 16:20:13
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/largest-number-at-least-twice-of-others/
 */

class Solution
{
    public int dominantIndex(int[] nums)
    {
        int l = nums.length;
        PriorityQueue<Integer> pQueue = new PriorityQueue<>((i1, i2) ->
        {
            return i2 - i1;
        });
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < l; i++)
        {
            map.put(nums[i], i);
            pQueue.add(nums[i]);
        }
        int max = pQueue.poll();
        int secondMax = 0;
        if (l > 1)
        {
            secondMax = pQueue.poll();
        }
        return max >= secondMax * 2 ? map.get(max) : -1;
    }
}