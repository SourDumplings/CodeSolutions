/*
 * @Author: SourDumplings
 * @Date: 2020-10-16 10:50:23
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/copy-list-with-random-pointer/
 */

class Solution
{
    public Node copyRandomList(Node head)
    {
        if (head == null)
        {
            return null;
        }
        Map<Node, Node> map = new HashMap<>();
        Node newHead = new Node(head.val);
        map.put(head, newHead);
        Node p1 = head.next, p2 = newHead;
        while (p1 != null)
        {
            p2.next = new Node(p1.val);
            p2 = p2.next;
            map.put(p1, p2);
            p1 = p1.next;
        }
        p1 = head;
        p2 = newHead;
        while (p1 != null)
        {
            if (p1.random != null)
            {
                p2.random = map.get(p1.random);
            }
            else
            {
                p2.random = null;
            }
            p1 = p1.next;
            p2 = p2.next;
        }
        return newHead;
    }
}