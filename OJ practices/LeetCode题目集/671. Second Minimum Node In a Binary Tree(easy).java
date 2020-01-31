/*
 * @Author: SourDumplings
 * @Date: 2019-10-13 20:38:21
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/second-minimum-node-in-a-binary-tree/
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
    public int findSecondMinimumValue(TreeNode root)
    {
        if (root == null || root.left == null)
        {
            return -1;
        }
        int m = root.val;
        int l = findSecond(root.left, m);
        int r = findSecond(root.right, m);
        return l < r && l != -1 || r == -1 ? l : r;
    }

    private int findSecond(TreeNode node, int m)
    {
        int v = node.val;
        if (v > m)
        {
            return v;
        }
        else if (node.left != null)
        {
            int l = findSecond(node.left, m);
            int r = findSecond(node.right, m);
            return l < r && l != -1 || r == -1 ? l : r;
        }
        return -1;
    }
}