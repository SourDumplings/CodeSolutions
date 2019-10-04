/*
 * @Autor: SourDumplings
 * @Date: 2019-10-04 10:18:47
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/diameter-of-binary-tree/
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
    private int ans = 0;

    public int diameterOfBinaryTree(TreeNode root)
    {
        if (root == null)
        {
            return 0;
        }
        else
        {
            ans = 1;
            depth(root);
            return ans - 1;
        }
    }

    private int depth(TreeNode p)
    {
        if (p == null)
        {
            return 0;
        }
        int l = depth(p.left);
        int r = depth(p.right);
        ans = Math.max(l + r + 1, ans);
        return Math.max(l, r) + 1;
    }
}