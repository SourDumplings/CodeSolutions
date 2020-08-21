/*
 * @Author: SourDumplings
 * @Date: 2020-08-21 16:53:04
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/reverse-linked-list-ii/
 */

class Solution
{
    public ListNode reverseBetween(ListNode head, int m, int n)
    {
        if (n - m < 1)
        {
            return head;
        }
        ListNode f = new ListNode(0);
        f.next = head;

        ListNode h = f;
        ListNode t = f;
        ListNode p = h;

        for (int i = 0; i <= n; i++)
        {
            if (i == m - 1)
            {
                h = p;
            }
            if (i == n)
            {
                t = p.next;
            }
            p = p.next;
        }
        p = h.next;
        while (p.next != t)
        {
            ListNode temp = p.next;
            p.next = temp.next;
            temp.next = h.next;
            h.next = temp;
        }
        return f.next;
    }
}