import java.util.Stack;

/*
 * @Autor: SourDumplings
 * @Date: 2019-10-02 11:48:56
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/convert-bst-to-greater-tree
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
    private int sum = 0;

    public TreeNode convertBST(TreeNode root)
    {
        Stack<TreeNode> S = new Stack<>();
        TreeNode temp = root;
        while (true)
        {
            TreeNode rightMost = root;
            while (rightMost != null)
            {
                S.push(rightMost);
                rightMost = rightMost.right;
            }
            if (S.empty())
            {
                break;
            }
            rightMost = S.pop();
            sum += rightMost.val;
            rightMost.val = sum;
            root = rightMost.left;
        }
        return temp;
    }
}