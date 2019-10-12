/*
 * @Author: SourDumplings
 * @Date: 2019-08-28 12:44:36
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/delete-node-in-a-linked-list/
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
    public void deleteNode(ListNode node)
    {
        if (node == null || node.next == null)
        {
            return;
        }
        ListNode p = node.next;
        node.val = p.val;
        node.next = p.next;
    }
}