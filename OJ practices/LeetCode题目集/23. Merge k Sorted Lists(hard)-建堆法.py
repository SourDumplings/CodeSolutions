'''
@Autor: SourDumplings
@Date: 2020-01-25 22:01:49
@Link: https://github.com/SourDumplings/
@Email: changzheng300@foxmail.com
@Description: https://leetcode.com/problems/merge-k-sorted-lists/
'''

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None
from queue import PriorityQueue
from typing import List


class Solution:
    def mergeKLists(self, lists: List[ListNode]) -> ListNode:
        t = h = ListNode(-1)
        pq = PriorityQueue()
        for l in lists:
            while l is not None:
                pq.put(l.val)
                l = l.next
        
        while not pq.empty():
            t.next = ListNode(pq.get())
            t = t.next
        return h.next
