'''
@Author: SourDumplings
@Date: 2020-01-26 12:04:06
@Link: https://github.com/SourDumplings/
@Email: changzheng300@foxmail.com
@Description: https://leetcode.com/problems/swap-nodes-in-pairs/
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None


class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        h = ListNode(-1)
        h.next = head
        f = h
        a = head
        while a is not None:
            b = a.next
            if b is not None:
                a.next = b.next
                f.next = b
                b.next = a
            f = a
            a = f.next
        return h.next
