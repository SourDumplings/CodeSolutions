'''
@Author: SourDumplings
@Date: 2020-01-25 20:16:22
@Link: https://github.com/SourDumplings/
@Email: changzheng300@foxmail.com
@Description: https://leetcode.com/problems/merge-k-sorted-lists/

将所有的元素都收集起来，对该数值列表排序，再一个一个插入到链表中即可
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        h = ListNode(-1)
        t = h
        vals = list()
        for l in lists:
            while l is not None:
                vals.append(l.val)
                l = l.next
        
        vals.sort()
        for v in vals:
            t.next = ListNode(v)
            t = t.next
        return h.next
