/*
 * @Author: SourDumplings
 * @Date: 2020-08-27 19:06:10
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/
 */

class Solution
{
    public ListNode deleteDuplicates(ListNode head)
    {
        ListNode h = new ListNode(0);
        h.next = head;
        ListNode f = h;
        ListNode p = head;
        if (p == null)
        {
            return null;
        }
        ListNode r = head.next;
        if (r == null)
        {
            return head;
        }
        while (true)
        {
            while (r != null && r.val == p.val)
            {
                r = r.next;
            }
            if (r == null)
            {
                if (r != p.next)
                {
                    f.next = null;
                }
                break;
            }
            else if (r != p.next)
            {
                f.next = r;
                p = r;
                r = p.next;
            }
            else
            {
                f = f.next;
                if (f != null)
                {
                    p = f.next;
                }
                else
                {
                    break;
                }
                if (p != null)
                {
                    r = p.next;
                }
                else
                {
                    break;
                }
            }
        }
        return h.next;
    }
}
