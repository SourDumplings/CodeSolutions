/*
 * @Author: SourDumplings
 * @Date: 2020-10-03 20:31:16
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/sum-root-to-leaf-numbers/
 */

class Solution
{
    private int res = 0;
    private int thisNum = 0;

    public int sumNumbers(TreeNode root)
    {
        if (root != null)
        {
            dfs(root);
        }
        return res;
    }

    private void dfs(TreeNode node)
    {
        thisNum = thisNum * 10 + node.val;
        if (node.right == null && node.left == null)
        {
            res += thisNum;
        }
        else
        {
            if (node.left != null)
            {
                dfs(node.left);
            }
            if (node.right != null)
            {
                dfs(node.right);
            }
        }
        thisNum = (thisNum - node.val) / 10;
    }
}