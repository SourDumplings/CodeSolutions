/*
 * @Autor: SourDumplings
 * @Date: 2019-12-08 22:45:03
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/add-two-numbers/
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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2)
    {
        ListNode head = new ListNode(0);
        head.next = null;
        ListNode p1 = l1, p2 = l2, p = head;
        boolean flag = false;
        int v1, v2;
        while (p1 != null || p2 != null)
        {
            p.next = new ListNode(0);
            p = p.next;
            p.next = null;
            if (p1 != null)
            {
                v1 = p1.val;
                p1 = p1.next;
            }
            else
            {
                v1 = 0;
            }
            if (p2 != null)
            {
                v2 = p2.val;
                p2 = p2.next;
            }
            else
            {
                v2 = 0;
            }
            p.val = v1 + v2;
            if (flag)
            {
                ++p.val;
                flag = false;
            }
            if (p.val >= 10)
            {
                p.val -= 10;
                flag = true;
            }
        }
        if (flag)
        {
            p.next = new ListNode(1);
            p.next.next = null;
        }
        return head.next;
    }
}