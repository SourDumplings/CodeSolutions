/*
 * @Autor: SourDumplings
 * @Date: 2019-09-25 17:53:35
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/path-sum-iii/
 * 
 * 暴力从每个点都作为起点来个DFS，时间复杂度为O(n^2)
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
    public int pathSum(TreeNode root, int sum)
    {
        if (root == null)
        {
            return 0;
        }
        int res = 0;
        res += dfs(root, sum, 0);
        res += pathSum(root.left, sum);
        res += pathSum(root.right, sum);
        return res;
    }

    int dfs(TreeNode root, int sum, int thisV)
    {
        if (root == null)
        {
            return 0;
        }
        thisV += root.val;
        int res = 0;
        if (thisV == sum)
        {
            res++;
        }
        res += dfs(root.left, sum, thisV) + dfs(root.right, sum, thisV);
        return res;
    }
}