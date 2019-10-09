/*
 * @Autor: SourDumplings
 * @Date: 2019-10-09 21:31:53
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/construct-string-from-binary-tree/
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
    private StringBuilder sb = new StringBuilder();

    public String tree2str(TreeNode t)
    {
        if (t != null)
        {
            preOrder(t);
        }
        return sb.toString();
    }

    private void preOrder(TreeNode t)
    {
        sb.append(t.val);
        if (t.left != null || t.right != null)
        {
            sb.append('(');
        }
        if (t.left != null)
        {
            preOrder(t.left);
        }
        if (t.left != null || t.right != null)
        {
            sb.append(')');
        }
        if (t.right != null)
        {
            sb.append('(');
            preOrder(t.right);
            sb.append(')');
        }
    }
}