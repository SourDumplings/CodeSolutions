/*
 * @Author: SourDumplings
 * @Date: 2020-01-27 17:34:48
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/reverse-nodes-in-k-group/
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
    public ListNode reverseKGroup(ListNode head, int k)
    {
        ListNode h = new ListNode(-1); // 头空结点
        h.next = head;
        ListNode f = head, l = head; // 摘除的子列的首尾结点
        ListNode a = h, b = h; // a 是下一轮头插法的头，b 是本轮头插法的头
        ListNode p = f; // 头插法的动结点
        while (f != null)
        {
            for (int i = 0; i < k - 1 && l != null; i++)
            {
                l = l.next;
            }
            if (l == null)
            {
                break;
            }
            head = l.next;
            a.next = head;
            b = a;
            a = f;
            p = f;
            f = head;
            l.next = null;
            l = f;
            while (p != null)
            {
                ListNode temp = p.next;
                p.next = b.next;
                b.next = p;
                p = temp;
            }
        }
        return h.next;
    }
}