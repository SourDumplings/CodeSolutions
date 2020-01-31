import java.util.HashSet;
import java.util.Set;

/*
 * @Author: SourDumplings
 * @Date: 2019-10-12 08:05:38
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
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
    public boolean findTarget(TreeNode root, int k)
    {
        Set<Integer> set = new HashSet<>();
        return find(root, k, set);
    }

    private boolean find(TreeNode node, int k, Set<Integer> set)
    {
        if (node == null)
        {
            return false;
        }
        if (set.contains(k - node.val))
        {
            return true;
        }
        set.add(node.val);
        return find(node.left, k, set) || find(node.right, k, set);
    }
}