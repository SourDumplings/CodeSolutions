import java.util.Stack;

import javafx.util.Pair;

/*
 * @Autor: SourDumplings
 * @Date: 2019-10-10 08:10:23
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/merge-two-binary-trees/
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
    public TreeNode mergeTrees(TreeNode t1, TreeNode t2)
    {
        Stack<Pair<TreeNode, TreeNode>> S = new Stack<>();
        if (t1 != null && t2 != null)
        {
            t1.val += t2.val;
            S.push(new Pair<>(t1, t2));
        }
        else if (t1 == null)
        {
            return t2;
        }
        while (!S.isEmpty())
        {
            Pair<TreeNode, TreeNode> p = S.pop();
            TreeNode node1 = p.getKey();
            TreeNode node2 = p.getValue();
            if (node1.left != null)
            {
                if (node2.left != null)
                {
                    node1.left.val += node2.left.val;
                    S.push(new Pair<>(node1.left, node2.left));
                }
            }
            else if (node2.left != null)
            {
                node1.left = new TreeNode(node2.left.val);
                S.push(new Pair<>(node1.left, node2.left));
            }
            if (node1.right != null)
            {
                if (node2.right != null)
                {
                    node1.right.val += node2.right.val;
                    S.push(new Pair<>(node1.right, node2.right));
                }
            }
            else if (node2.right != null)
            {
                node1.right = new TreeNode(node2.right.val);
                S.push(new Pair<>(node1.right, node2.right));
            }
        }
        return t1;
    }
}