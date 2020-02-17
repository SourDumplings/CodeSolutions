'''
@Author: SourDumplings
@Date: 2020-02-17 21:46:23
@Link: https://github.com/SourDumplings/
@Email: changzheng300@foxmail.com
@Description: https://leetcode-cn.com/problems/same-tree/
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None


class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        return (p is not None and q is not None and p.val == q.val and self.isSameTree(p.left, q.left) and self.isSameTree(p.right, q.right)) or (p is None and q is None)
