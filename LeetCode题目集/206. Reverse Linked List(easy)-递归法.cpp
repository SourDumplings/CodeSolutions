/*
 * @Author: SourDumplings
 * @Date: 2019-08-19 13:10:38
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/reverse-linked-list/
 * 
 * 试想链表n1->n2->...->nk-1->nk->nk+1->...->nm
 * 在后半部分nk到nm已经逆序之后为：
 * n1->n2->...->nk-1->nk<-nk+1<-...<-nm
 * 此时nk的下一个为NULL，这时需要做的是让nk的下一个指向nk-1即可
 * 试想一下递归基，即最后一个结点nm时，返回还是nm
 * 其上层调用会发生的是nm-1的下一个即nm，其下一个会指向nm-1，即：
 * n1->n2->...->nm-2->nm-1<-nm
 * 然后返回nm，其上一层调用会发生nm-2的下一个即nm-1，其下一个指向nm-2，然后返回nm
 * 以此类推，直至完成全列的逆序
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
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head;
        }
        ListNode *p = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return p;
    }
};