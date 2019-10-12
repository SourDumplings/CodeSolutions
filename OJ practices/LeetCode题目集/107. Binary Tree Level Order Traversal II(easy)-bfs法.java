import java.util.List;

/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/binary-tree-level-order-traversal-ii/
 * @Date: 2019-03-04 18:20:04
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
    public List<List<Integer>> levelOrderBottom(TreeNode root)
    {
        List<List<Integer>> res = new LinkedList<List<Integer>>();
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        if (root == null)
        {
            return res;
        }
        q.add(root);
        while (!q.isEmpty())
        {
            int levelNum = q.size();
            List<Integer> subList = new LinkedList<Integer>();
            for (int i = 0; i < levelNum; i++)
            {
                TreeNode node = q.poll();
                if (node.left != null)
                {
                    q.add(node.left);
                }
                if (node.right != null)
                {
                    q.add(node.right);
                }
                subList.add(node.val);
            }
            res.add(0, subList);
        }
        return res;

    }
}