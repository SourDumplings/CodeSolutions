/*
 * @Autor: SourDumplings
 * @Date: 2019-10-02 12:09:57
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/convert-bst-to-greater-tree/
 */

import java.util.Stack;
import java.util.function.Consumer;

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
    private int sum = 0;

    public TreeNode convertBST(TreeNode root)
    {
        if (root != null)
        {
            levelOrder(root, node ->
            {
                sum += node.val;
            });
            levelOrder(root, node ->
            {
                sum -= node.val;
                node.val += sum;
            });
        }
        return root;
    }

    private void levelOrder(TreeNode root, Consumer<TreeNode> f)
    {
        Stack<TreeNode> S = new Stack<>();
        while (true)
        {
            TreeNode leftMost = root;
            while (leftMost != null)
            {
                S.push(leftMost);
                leftMost = leftMost.left;
            }
            if (S.empty())
            {
                break;
            }
            leftMost = S.pop();
            f.accept(leftMost);
            root = leftMost.right;
        }
    }
}