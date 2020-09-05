/*
 * @Author: SourDumplings
 * @Date: 2020-09-05 22:00:05
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
 */

class Solution
{
    public TreeNode buildTree(int[] inorder, int[] postOrder)
    {
        if (inorder.length == 0)
        {
            return null;
        }
        int rootVal = postOrder[postOrder.length - 1];
        int leftEnd = inorder.length;
        for (int i = 0; i < inorder.length; i++)
        {
            if (inorder[i] == rootVal)
            {
                leftEnd = i;
                break;
            }
        }
        TreeNode root = new TreeNode(rootVal);
        root.left = build(inorder, 0, leftEnd, postOrder, 0, leftEnd);
        root.right = build(inorder, leftEnd + 1, inorder.length, postOrder, leftEnd, postOrder.length - 1);
        return root;
    }

    private TreeNode build(int[] inOrder, int inB, int inE, int[] postOrder, int postB, int postE)
    {
        if (inE <= inB)
        {
            return null;
        }
        int rootVal = postOrder[postE - 1];
        TreeNode root = new TreeNode(rootVal);
        int leftEnd = inE;
        for (int i = inB; i < inE; i++)
        {
            if (inOrder[i] == rootVal)
            {
                leftEnd = i;
                break;
            }
        }
        root.left = build(inOrder, inB, leftEnd, postOrder, postB, leftEnd - inB + postB);
        root.right = build(inOrder, leftEnd + 1, inE, postOrder, leftEnd - inB + postB, postE - 1);
        return root;
    }
}


