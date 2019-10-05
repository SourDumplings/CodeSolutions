/*
 * @Autor: SourDumplings
 * @Date: 2019-10-05 18:47:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/subtree-of-another-tree/
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
    public boolean isSubtree(TreeNode s, TreeNode t)
    {
        if (isEqual(s, t))
        {
            return true;
        }
        else
        {
            if (s != null)
            {
                return isSubtree(s.left, t) || isSubtree(s.right, t);
            }
            else
            {
                return t == null;
            }
        }
    }

    private boolean isEqual(TreeNode a, TreeNode b)
    {
        if (a == null)
        {
            return b == null;
        }
        else if (b == null)
        {
            return false;
        }
        else
        {
            return a.val == b.val && isEqual(a.left, b.left) && isEqual(a.right, b.right);
        }
    }
}