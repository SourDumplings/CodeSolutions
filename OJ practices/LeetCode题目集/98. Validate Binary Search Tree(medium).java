/*
 * @Author: SourDumplings
 * @Date: 2020-09-01 10:57:28
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/validate-binary-search-tree/
 */

class Solution
{
    List<Integer> inOrder = new ArrayList<>();

    public boolean isValidBST(TreeNode root)
    {
        inOrderTraversal(root);
        for (int i = 1; i < inOrder.size(); i++)
        {
            if (inOrder.get(i) <= inOrder.get(i - 1))
            {
                return false;
            }
        }
        return true;
    }

    private void inOrderTraversal(TreeNode node)
    {
        if (node != null)
        {
            inOrderTraversal(node.left);
            inOrder.add(node.val);
            inOrderTraversal(node.right);
        }
    }
}