import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Queue;

/*
 * @Author: SourDumplings
 * @Date: 2019-10-23 08:34:10
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/kth-largest-element-in-a-stream/
 */

class KthLargest
{
    private int k;
    private Queue<Integer> pq;

    public KthLargest(int k, int[] nums)
    {
        this.k = k;
        pq = new PriorityQueue<>(k);
        int n = nums.length;
        Arrays.sort(nums);
        for (int i = n - 1; i >= n - k && i >= 0; i--)
        {
            pq.add(nums[i]);
        }
    }

    public int add(int val)
    {
        if (pq.size() < k)
        {
            pq.add(val);
        }
        else if (val > pq.peek())
        {
            pq.poll();
            pq.add(val);
        }
        return pq.peek();
    }
}

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */