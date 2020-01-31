import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
 * @Author: SourDumplings
 * @Date: 2019-10-11 15:42:59
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/average-of-levels-in-binary-tree/
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
    public List<Double> averageOfLevels(TreeNode root)
    {
        List<Double> res = new ArrayList<>();
        Queue<TreeNode> q = new LinkedList<>();
        if (root != null)
        {
            q.add(root);
        }
        while (!q.isEmpty())
        {
            Queue<TreeNode> nextLevel = new LinkedList<>();
            long sum = 0;
            int count = 0;
            while (!q.isEmpty())
            {
                TreeNode node = q.poll();
                sum += node.val;
                ++count;
                if (node.left != null)
                {
                    nextLevel.add(node.left);
                }
                if (node.right != null)
                {
                    nextLevel.add(node.right);
                }
            }
            res.add((double) sum / count);
            q = nextLevel;
        }
        return res;
    }
}