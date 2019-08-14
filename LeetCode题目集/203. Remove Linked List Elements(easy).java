/*
 * @Author: SourDumplings
 * @Date: 2019-08-14 08:53:40
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/remove-linked-list-elements/
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
    public ListNode removeElements(ListNode head, int val)
    {
        while (head != null && head.val == val)
        {
            head = head.next;
        }
        ListNode f = head, p = head;
        while (p != null)
        {
            if (p.val == val)
            {
                f.next = p.next;
                p = p.next;
            }
            else
            {
                f = p;
                p = p.next;
            }
        }
        return head;
    }
}