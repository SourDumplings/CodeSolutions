/*
 * @Author: SourDumplings
 * @Date: 2020-09-02 21:51:00
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/binary-tree-level-order-traversal/
 */

class Solution
{
    public List<List<Integer>> levelOrder(TreeNode root)
    {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null)
        {
            return res;
        }
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        while (!q.isEmpty())
        {
            List<TreeNode> thisLevel = new ArrayList<>();
            while (!q.isEmpty())
            {
                thisLevel.add(q.remove());
            }
            List<Integer> thisLevelRes = new ArrayList<>();
            for (TreeNode treeNode : thisLevel)
            {
                thisLevelRes.add(treeNode.val);
                if (treeNode.left != null)
                {
                    q.add(treeNode.left);
                }
                if (treeNode.right != null)
                {
                    q.add(treeNode.right);
                }
            }
            res.add(thisLevelRes);
        }
        return res;
    }
}
