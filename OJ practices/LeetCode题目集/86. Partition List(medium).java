/*
 * @Author: SourDumplings
 * @Date: 2020-08-28 10:38:46
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/partition-list/
 */

class Solution
{
    public ListNode partition(ListNode head, int x)
    {
        ListNode before = new ListNode(0);
        ListNode after = new ListNode(0);
        ListNode p = head;
        ListNode pB = before;
        ListNode pA = after;
        while (p != null)
        {
            if (p.val < x)
            {
                pB.next = new ListNode(p.val);
                pB = pB.next;
            }
            else
            {
                pA.next = new ListNode(p.val);
                pA = pA.next;
            }
            p = p.next;
        }
        pB.next = after.next;
        return before.next;
    }
}