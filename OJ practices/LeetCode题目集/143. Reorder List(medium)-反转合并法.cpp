/*
 * @Author: SourDumplings
 * @Date: 2020-10-29 18:00:22
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/reorder-list/
 * 
 * 注意到目标链表即为将原链表的左半端和反转后的右半端合并后的结果。

这样我们的任务即可划分为三步：

找到原链表的中点（参考「876. 链表的中间结点」）。

我们可以使用快慢指针来 O(N)O(N) 地找到链表的中间节点。
将原链表的右半端反转（参考「206. 反转链表」）。

我们可以使用迭代法实现链表的反转。
将原链表的两端合并。

因为两链表长度相差不超过 1，因此直接合并即可。
 */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (head == nullptr)
        {
            return;
        }
        ListNode *slow = head, *fast = head;
        while (fast->next != nullptr)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast->next == nullptr)
            {
                break;
            }
            fast = fast->next;
        }
        // 此时慢指针位于中点，将慢指针之后的部分逆序
        ListNode h;
        ListNode *p = slow->next;
        slow->next = nullptr;
        while (p != nullptr)
        {
            ListNode *temp = p;
            p = p->next;
            temp->next = h.next;
            h.next = temp;
        }
        // 合并
        p = h.next;
        ListNode *r = head;
        while (r != nullptr && p != nullptr)
        {
            ListNode *temp1 = r->next, *temp2 = p->next;
            r->next = p;
            p->next = temp1;
            r = temp1;
            p = temp2;
        }
    }
};