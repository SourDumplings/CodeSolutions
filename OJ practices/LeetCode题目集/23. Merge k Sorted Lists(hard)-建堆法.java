import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;
import java.util.Queue;

/*
 * @Autor: SourDumplings
 * @Date: 2020-01-25 21:47:27
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/merge-k-sorted-lists/
 */

/**
* Definition for singly-linked list.
* public class ListNode {
*     int val;
*     ListNode next;
*     ListNode(int x) { val = x; }
* }
*/
class Solution
{
    public ListNode mergeKLists(ListNode[] lists)
    {
        List<Integer> vals = new ArrayList<>();
        for (ListNode l : lists)
        {
            while (l != null)
            {
                vals.add(l.val);
                l = l.next;
            }
        }
        Queue<Integer> pq = new PriorityQueue<>(vals);
        ListNode h = new ListNode(-1);
        ListNode t = h;
        while (!pq.isEmpty())
        {
            int v = pq.poll();
            t.next = new ListNode(v);
            t = t.next;
        }
        return h.next;
    }
}