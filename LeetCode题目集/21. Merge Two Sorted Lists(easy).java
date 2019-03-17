/**
 * @Date    : 2019-01-08 11:17:21
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * https://leetcode.com/problems/merge-two-sorted-lists/
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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2)
    {
        ListNode l = new ListNode(0), p = null;
        l.next = null;
        p = l;
        while (l1 != null && l2 != null)
        {
            if (l1.val <= l2.val)
            {
                p.next = new ListNode(l1.val);
                l1 = l1.next;
            }
            else
            {
                p.next = new ListNode(l2.val);
                l2 = l2.next;
            }
            p = p.next;
        }
        while (l1 != null)
        {
            p.next = new ListNode(l1.val);
            p = p.next;
            l1 = l1.next;
        }
        while (l2 != null)
        {
            p.next = new ListNode(l2.val);
            p = p.next;
            l2 = l2.next;
        }
        return l.next;
    }
}

