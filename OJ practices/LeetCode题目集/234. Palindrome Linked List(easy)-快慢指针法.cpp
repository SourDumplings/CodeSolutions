/*
 * @Author: SourDumplings
 * @Date: 2021-01-11 09:08:17
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/palindrome-linked-list/
 * 
 * 思路是将后半部分逆置再比较，使用快慢指针找到逆置的起点
 * 时间复杂度 O(n)，空间复杂度 O(1)
 */

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        ListNode *fast = head, *slow = head;
        bool even = true;
        while (fast)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast)
            {
                fast = fast->next;
            }
            else
            {
                even = false;
            }
        }
        if (!slow)
        {
            // 只有一个结点
            return true;
        }

        ListNode *revHead = new ListNode(0);
        ListNode *p = slow;
        while (p)
        {
            ListNode *temp = p->next;
            p->next = revHead->next;
            revHead->next = p;
            p = temp;
        }
        ListNode *f = head, *r = revHead->next;
        if (even)
        {
            while (f != slow)
            {
                if (f->val != r->val)
                {
                    return false;
                }
                f = f->next;
                r = r->next;
            }
        }
        else
        {
            while (f->next != slow)
            {
                if (f->val != r->val)
                {
                    return false;
                }
                f = f->next;
                r = r->next;
            }
        }
        delete revHead;
        return true;
    }
};