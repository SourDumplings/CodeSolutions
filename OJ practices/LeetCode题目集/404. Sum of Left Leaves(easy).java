/*
 * @Autor: SourDumplings
 * @Date: 2019-09-23 08:12:07
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/sum-of-left-leaves/
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

    public int sumOfLeftLeaves(TreeNode root)
    {
        doSumOfLeftLeaves(root, null);
        return res;
    }

    public void doSumOfLeftLeaves(TreeNode x, TreeNode p)
    {
        if (x != null)
        {
            if (x.left == null && x.right == null)
            {
                if (p != null && x == p.left)
                {
                    res += x.val;
                }
            }
            else
            {
                if (x.left != null)
                {
                    doSumOfLeftLeaves(x.left, x);
                }
                if (x.right != null)
                {
                    doSumOfLeftLeaves(x.right, x);
                }
            }
        }
    }
}