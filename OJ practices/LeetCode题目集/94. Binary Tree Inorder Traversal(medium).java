/*
 * @Author: SourDumplings
 * @Date: 2020-08-23 10:49:47
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/binary-tree-inorder-traversal/
 */

 /**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

class Solution
{
    public List<Integer> inorderTraversal(TreeNode root)
    {
        List<Integer> res = new ArrayList<>();
        Stack<TreeNode> S = new Stack<>();
        while (true)
        {
            TreeNode leftMost = root;
            while (leftMost != null)
            {
                S.add(leftMost);
                leftMost = leftMost.left;
            }
            if (S.isEmpty())
            {
                break;
            }
            leftMost = S.pop();
            res.add(leftMost.val);
            root = leftMost.right;
        }
        return res;
    }
}