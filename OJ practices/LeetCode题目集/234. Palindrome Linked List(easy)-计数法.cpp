/*
 * @Author: SourDumplings
 * @Date: 2021-01-11 10:07:15
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/palindrome-linked-list/
 
 * 思路是将后半部分逆置再比较，使用计数找到逆置的起点
 * 时间复杂度 O(n)，空间复杂度 O(1)
 */

class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        int n = 0;
        ListNode *p = head;
        while (p)
        {
            ++n;
            p = p->next;
        }
        if (n == 1)
        {
            return true;
        }
        p = head;
        int count = 0;
        while (count < n / 2)
        {
            ++count;
            p = p->next;
        }
        ListNode *p0 = p;
        if (n % 2)
        {
            p = p->next;
        }
        ListNode *revHead = new ListNode(0);
        while (p)
        {
            ListNode *temp = p->next;
            p->next = revHead->next;
            revHead->next = p;
            p = temp;
        }
        ListNode *f = head, *r = revHead->next;
        while (f != p0)
        {
            if (f->val != r->val)
            {
                return false;
            }
            f = f->next;
            r = r->next;
        }
        return true;
    }
};
