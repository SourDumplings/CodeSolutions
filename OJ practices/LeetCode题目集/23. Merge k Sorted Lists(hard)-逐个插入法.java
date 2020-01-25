/*
 * @Autor: SourDumplings
 * @Date: 2020-01-25 20:21:42
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/merge-k-sorted-lists/
 * 
 * 一个个插入，每次插入都是要扫描所有列表的第一个元素先找出最小的元素
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
    public ListNode mergeKLists(ListNode[] lists)
    {
        ListNode h = new ListNode(-1);
        h.next = null;
        ListNode t = h;
        int p = -1;
        int l = lists.length;
        do
        {
            int min = Integer.MAX_VALUE;
            p = -1;
            for (int i = 0; i < l; i++)
            {
                if (lists[i] != null && lists[i].val < min)
                {
                    min = lists[i].val;
                    p = i;
                }
            }
            if (p != -1)
            {
                lists[p] = lists[p].next;
                t.next = new ListNode(min);
                t = t.next;
                t.next = null;
            }
        }
        while (p != -1);
        return h.next;
    }
}