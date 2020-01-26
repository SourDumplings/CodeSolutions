/*
 * @Autor: SourDumplings
 * @Date: 2020-01-26 11:50:02
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/swap-nodes-in-pairs/
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
    public ListNode swapPairs(ListNode head)
    {
        ListNode h = new ListNode(-1);
        h.next = head;
        ListNode f = h;
        ListNode a = head, b = null;
        while (a != null)
        {
            b = a.next;
            if (b != null)
            {
                a.next = b.next;
                b.next = a;
                f.next = b;
            }
            f = a;
            a = f.next;
        }
        return h.next;
    }
}