/*
 * @Author: SourDumplings
 * @Date: 2020-09-07 22:43:31
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/
 */

class Solution
{
    private TreeNode last = null;

    public void flatten(TreeNode root)
    {
        if (root != null)
        {
            TreeNode left = root.left;
            TreeNode right = root.right;
            flatten(right);
            flatten(left);
            root.right = last;
            root.left = null;
            last = root;
        }
    }
}