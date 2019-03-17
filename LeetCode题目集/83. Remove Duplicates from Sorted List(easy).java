/**
 * @Date    : 2019-02-19 22:26:44
 * @Author  : 酸饺子 (changzheng300@foxmail.com)
 * @Link    : https://github.com/SourDumplings
 * @Version : $Id$
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list/
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
    public ListNode deleteDuplicates(ListNode head)
    {
        if (head == null)
        {
            return head;
        }
        ListNode f = head, b = head.next;
        while (b != null)
        {
            if (f.val == b.val)
            {
                f.next = b.next;
            }
            else
                f = b;
            b = f.next;
        }
        return head;
    }
}

