/*
 * @Author: SourDumplings
 * @Date: 2020-09-04 09:59:06
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
 */

class Solution
{
    public TreeNode buildTree(int[] preorder, int[] inorder)
    {
        if (preorder.length == 0)
        {
            return null;
        }
        int rootVal = preorder[0];
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
        root.left = build(preorder, 1, leftEnd + 1, inorder, 0, leftEnd);
        root.right = build(preorder, leftEnd + 1, preorder.length, inorder, leftEnd + 1,
            inorder.length);
        return root;
    }

    private TreeNode build(int[] preOrder, int preB, int preE, int[] inOrder, int inB, int inE)
    {
        if (preE <= preB)
        {
            return null;
        }
        int rootVal = preOrder[preB];
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
        root.left = build(preOrder, preB + 1, leftEnd - inB + preB + 1, inOrder, inB, leftEnd);
        root.right = build(preOrder, leftEnd - inB + preB + 1, preE, inOrder, leftEnd + 1, inE);
        return root;
    }
}


