/*
 * @Author: SourDumplings
 * @Date: 2019-10-10 08:05:46
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
        if (t1 != null)
        {
            if (t2 != null)
            {
                t1.val += t2.val;
            }
        }
        else if (t2 != null)
        {
            t1 = new TreeNode(t2.val);
        }
        if (t1 != null && t2 != null)
        {
            t1.left = mergeTrees(t1.left, t2.left);
            t1.right = mergeTrees(t1.right, t2.right);
        }
        return t1;
    }
}