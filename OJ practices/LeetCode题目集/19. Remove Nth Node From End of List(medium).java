/*
 * @Author: SourDumplings
 * @Date: 2020-01-19 09:34:11
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
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
    public ListNode removeNthFromEnd(ListNode head, int n)
    {
        ListNode f = head;
        ListNode p = f;
        ListNode t = p;

        for (int i = 0; i < n - 1; i++)
        {
            t = t.next;
        }
        if (t.next == null)
        {
            return f.next;
        }
        else
        {
            while (t.next != null)
            {
                f = p;
                p = p.next;
                t = t.next;
            }
        }

        f.next = p.next;
        return head;
    }
}