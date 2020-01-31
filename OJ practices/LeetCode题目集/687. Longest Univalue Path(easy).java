/*
 * @Author: SourDumplings
 * @Date: 2019-10-16 17:38:48
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/longest-univalue-path/
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
    private int res;

    public int longestUnivaluePath(TreeNode root)
    {
        res = 0;
        arrowLength(root);
        return res;
    }

    int arrowLength(TreeNode node)
    {
        if (node == null)
        {
            return 0;
        }
        int left = arrowLength(node.left);
        int right = arrowLength(node.right);
        int leftArrow = 0;
        int rightArrow = 0;
        if (node.left != null && node.val == node.left.val)
        {
            leftArrow = left + 1;
        }
        if (node.right != null && node.val == node.right.val)
        {
            rightArrow = right + 1;
        }
        res = Math.max(leftArrow + rightArrow, res);
        return Math.max(leftArrow, rightArrow);
    }
}