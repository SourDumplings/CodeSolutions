/*
 * @Autor: SourDumplings
 * @Date: 2019-10-05 09:53:14
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/binary-tree-tilt/
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
    private int res = 0;

    public int findTilt(TreeNode root)
    {
        doFindTilt(root);
        return res;
    }

    private int doFindTilt(TreeNode node)
    {
        if (node == null)
        {
            return 0;
        }
        else
        {
            int l = doFindTilt(node.left);
            int r = doFindTilt(node.right);
            int temp = Math.abs(l - r);
            res += temp;
            return l + r + node.val;
        }
    }
}