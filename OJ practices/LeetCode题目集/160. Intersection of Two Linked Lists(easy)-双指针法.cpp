/*
 * @Author: SourDumplings
 * @Date: 2020-12-02 20:25:16
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/intersection-of-two-linked-lists/
 * 
 * 分别用两个指针指向链表进行遍历，
 * 将先到达尾部结点的短链表指针重置到长链表的头，继续前进
 * 长链表指针到达尾部后重置在短链表的头，继续前进，此时短链表刚好在长链表上走过了二者距离之差
 * 然后二者的相遇点即为交点
 * 
 * 参考：https://leetcode-cn.com/problems/intersection-of-two-linked-lists/solution/xiang-jiao-lian-biao-by-leetcode/
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *p1 = headA, *p2 = headB;
        while (p1 && p2)
        {
            p1 = p1->next;
            p2 = p2->next;
        }
        if (p1)
        {
            p2 = headA;
            while (p1)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            p1 = headB;
        }
        else
        {
            p1 = headB;
            while (p2)
            {
                p1 = p1->next;
                p2 = p2->next;
            }
            p2 = headA;
        }
        while (p1 && p2)
        {
            if (p1 == p2)
            {
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return nullptr;
    }
};