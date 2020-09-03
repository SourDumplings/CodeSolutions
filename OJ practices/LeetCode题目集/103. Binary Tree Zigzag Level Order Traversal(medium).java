/*
 * @Author: SourDumplings
 * @Date: 2020-09-03 09:33:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/
 */

class Solution
{
    public List<List<Integer>> zigzagLevelOrder(TreeNode root)
    {
        List<List<Integer>> res = new ArrayList<>();
        if (root == null)
        {
            return res;
        }
        Queue<TreeNode> q = new LinkedList<>();
        q.add(root);
        boolean flag = true;
        while (!q.isEmpty())
        {
            List<TreeNode> thisLevel = new ArrayList<>();
            while (!q.isEmpty())
            {
                thisLevel.add(q.remove());
            }
            List<Integer> thisLevelRes = new ArrayList<>();
            int n = thisLevel.size();
            if (flag)
            {
                for (int i = 0; i < n; i++)
                {
                    TreeNode treeNode = thisLevel.get(i);
                    thisLevelRes.add(treeNode.val);
                }
            }
            else
            {
                for (int i = n - 1; i >= 0; i--)
                {
                    TreeNode treeNode = thisLevel.get(i);
                    thisLevelRes.add(treeNode.val);
                }
            }
            flag = !flag;
            for (TreeNode treeNode : thisLevel)
            {
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
