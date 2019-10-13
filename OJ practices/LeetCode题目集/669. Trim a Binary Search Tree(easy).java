/*
 * @Autor: SourDumplings
 * @Date: 2019-10-13 14:29:22
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/trim-a-binary-search-tree/
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
    public TreeNode trimBST(TreeNode root, int L, int R)
    {
        if (root != null)
        {
            int v = root.val;
            if (v < L)
            {
                return trimBST(root.right, L, R);
            }
            else if (R < v)
            {
                return trimBST(root.left, L, R);
            }
            else
            {
                root.left = trimBST(root.left, L, R);
                root.right = trimBST(root.right, L, R);
            }
        }
        return root;
    }
}