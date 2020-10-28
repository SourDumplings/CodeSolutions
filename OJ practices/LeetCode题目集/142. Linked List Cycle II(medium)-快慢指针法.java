/*
 * @Author: SourDumplings
 * @Date: 2020-10-28 20:55:45
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/linked-list-cycle-ii/
 * 
 * 参考自：https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode-solution/
 * 使用快慢指针，快指针每次移动2个 node，慢指针每次移动1个，
 * 如果有环，二者必相遇
 * 假设 head 到入环点距离为 a，入环点到二者相遇点距离为 b，之后再走 c 距离回到入环点，即环长为 b + c
 * 因为快指针速度是慢指针的二倍，则有 a + n * (b + c) + b  = 2 * (a + b)
 * 即 a = c + (n - 1) * (b + c)
 * 因此，在快慢指针相遇时，再来一个慢指针从 head 出发，走 a 距离之后必能和原来的慢指针在入环点相遇
 */

public class Solution
{
    public ListNode detectCycle(ListNode head)
    {
        if (head == null)
        {
            return null;
        }
        ListNode fast = head;
        ListNode slow = head;
        while (true)
        {
            slow = slow.next;
            fast = fast.next;
            if (fast == null)
            {
                return null;
            }
            fast = fast.next;
            if (slow != null && fast != null)
            {
                if (slow == fast)
                {
                    ListNode p = head;
                    while (p != slow)
                    {
                        p = p.next;
                        slow = slow.next;
                    }
                    return p;
                }
            }
            else
            {
                return null;
            }

        }
    }
}
