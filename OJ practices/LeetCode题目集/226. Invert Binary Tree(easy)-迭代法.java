import java.util.LinkedList;
import java.util.Queue;

/*
 * @Author: SourDumplings
 * @Date: 2019-08-23 21:46:48
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/invert-binary-tree/
 * 
 * 层序遍历交换各结点的左右子树即可
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
    public TreeNode invertTree(TreeNode root)
    {
        if (root == null)
        {
            return null;
        }
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty())
        {
            TreeNode r = q.remove();
            TreeNode temp = r.left;
            r.left = r.right;
            r.right = temp;
            if (r.left != null)
                q.add(r.left);
            if (r.right != null)
                q.add(r.right);
        }
        return root;
    }
}
