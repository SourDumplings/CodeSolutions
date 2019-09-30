/*
 * @Autor: SourDumplings
 * @Date: 2019-09-30 19:43:22
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
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
    private int res = Integer.MAX_VALUE;
    private int lastVal = 0;
    private boolean isFirst = true;

    public int getMinimumDifference(TreeNode root)
    {
        if (root == null)
        {
            return 0;
        }
        levelOrder(root);
        return res;
    }

    void levelOrder(TreeNode root)
    {
        if (root.left != null)
        {
            levelOrder(root.left);

        }
        visit(root);
        if (root.right != null)
        {
            levelOrder(root.right);

        }
    }

    void visit(TreeNode node)
    {
        int val = node.val;
        if (isFirst)
        {
            isFirst = false;
        }
        else if (val - lastVal < res)
        {
            res = val - lastVal;
        }
        lastVal = val;
    }
}