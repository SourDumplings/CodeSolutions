/*
 * @Author: SourDumplings
 * @Date: 2020-05-08 20:02:20
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description:
 */

/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode next; ListNode(int
 * x) { val = x; } }
 */
class Solution
{
    public ListNode rotateRight(ListNode head, int k)
    {
        if (head == null)
        {
            return null;
        }

        int n = 0;
        ListNode p = head;
        ListNode tail = head;
        while (p != null)
        {
            ++n;
            if (p.next == null)
            {
                tail = p;
            }
            p = p.next;
        }
        k %= n;
        int newHeadIndex = n - k;
        tail.next = head;

        ListNode newHead = head;
        for (int i = 0; i < newHeadIndex; i++)
        {
            newHead = newHead.next;

        }
        p = newHead;
        for (int i = 0; i < n - 1; i++)
        {
            p = p.next;
        }
        p.next = null;
        return newHead;
    }
}