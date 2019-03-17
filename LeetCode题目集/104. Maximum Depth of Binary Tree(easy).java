/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/maximum-depth-of-binary-tree/
 * @Date: 2019-03-03 17:07:13
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
    public int maxDepth(TreeNode root)
    {
        return getHeight(root);
    }

    public int getHeight(TreeNode node)
    {
        if (node == null)
        {
            return 0;
        }
        else
        {
            int lH = getHeight(node.left);
            int rH = getHeight(node.right);
            return lH > rH ? lH + 1 : rH + 1;
        }
    }
}