/*
 * @Author: SourDumplings
 * @Date: 2019-08-27 21:33:12
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
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
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q)
    {
        while (true)
        {
            if (p.val < root.val)
            {
                if (q.val < root.val)
                {
                    root = root.left;
                }
                else
                {
                    return root;
                }
            }
            else if (p.val == root.val)
            {
                return root;
            }
            else
            {
                if (q.val > root.val)
                {
                    root = root.right;
                }
                else
                {
                    return root;
                }
            }
        }
    }
}