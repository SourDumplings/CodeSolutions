/*
 * @Author: SourDumplings
 * @Date: 2020-10-28 20:31:48
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/linked-list-cycle-ii/
 */

 /**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */

public class Solution
{
    public ListNode detectCycle(ListNode head)
    {
        Set<ListNode> set = new HashSet<>();
        ListNode p = head;
        while (p != null)
        {
            if (set.contains(p))
            {
                return p;
            }
            set.add(p);
            p = p.next;
        }
        return null;
    }
}