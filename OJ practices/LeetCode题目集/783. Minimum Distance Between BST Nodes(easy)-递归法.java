/*
 * @Author: SourDumplings
 * @Date: 2019-11-08 19:04:09
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/minimum-distance-between-bst-nodes/
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
    private int res = Integer.MAX_VALUE;
    private int lastNum = -1;

    public int minDiffInBST(TreeNode root)
    {
        inOrder(root);
        return res;
    }

    private void inOrder(TreeNode node)
    {
        if (node != null)
        {
            inOrder(node.left);
            if (lastNum == -1)
            {
                lastNum = node.val;
            }
            else
            {
                int thisVal = node.val;
                if (thisVal - lastNum < res)
                {
                    res = thisVal - lastNum;
                }
                lastNum = thisVal;
            }
            inOrder(node.right);
        }
    }
}