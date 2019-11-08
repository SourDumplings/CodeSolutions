import java.util.Stack;

/*
 * @Autor: SourDumplings
 * @Date: 2019-11-08 18:55:12
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
    public int minDiffInBST(TreeNode root)
    {
        int lastNum = -1;
        int res = Integer.MAX_VALUE;
        Stack<TreeNode> S = new Stack<>();
        while (true)
        {
            TreeNode leftMost = root;
            while (leftMost != null)
            {
                S.push(leftMost);
                leftMost = leftMost.left;
            }
            if (S.isEmpty())
            {
                break;
            }
            leftMost = S.pop();
            int thisVal = leftMost.val;
            if (lastNum == -1)
            {
                lastNum = thisVal;
            }
            else
            {
                if (thisVal - lastNum < res)
                {
                    res = thisVal - lastNum;
                }
                lastNum = thisVal;
            }
            root = leftMost.right;
        }
        return res;
    }
}