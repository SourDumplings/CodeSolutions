/*
 * @Author: SourDumplings
 * @Date: 2019-08-30 20:03:55
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/binary-tree-paths/
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
    public List<String> binaryTreePaths(TreeNode root)
    {
        List<String> res = new ArrayList<String>();
        if (root == null)
        {
            return res;
        }
        List<Integer> path = new ArrayList<Integer>();
        dfs(root, path, res);
        return res;
    }

    void dfs(TreeNode root, List<Integer> path, List<String> res)
    {
        path.add(root.val);
        if (root.left == null && root.right == null)
        {
            record(path, res);
        }
        if (root.left != null)
        {
            dfs(root.left, path, res);
        }
        if (root.right != null)
        {
            dfs(root.right, path, res);
        }
        path.remove(path.size() - 1);
    }

    void record(List<Integer> path, List<String> res)
    {
        boolean first = true;
        StringBuilder strB = new StringBuilder();
        for (Integer i : path)
        {
            if (!first)
            {
                strB.append("->");
            }
            else
                first = false;
            strB.append(i.toString());
        }
        res.add(strB.toString());
    }
}