import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-28 08:48:54
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/find-mode-in-binary-search-tree/
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
    private int count = 0;
    private int lastVal = -1;
    private int maxCount = 0;
    private boolean isFirst = true;

    public int[] findMode(TreeNode root)
    {
        List<Integer> res = new ArrayList<>();
        if (root != null)
        {
            levelOrder(root, res);
            record(lastVal, res);
        }
        int n = res.size();
        int[] realRes = new int[n];
        int i = 0;
        for (int in : res)
        {
            realRes[i++] = in;
        }
        return realRes;
    }

    private void levelOrder(TreeNode root, List<Integer> res)
    {
        Stack<TreeNode> S = new Stack<>();
        while (true)
        {
            TreeNode leftMost = root;
            while (leftMost != null)
            {
                S.push(leftMost);
                leftMost = leftMost.left;
            }
            if (S.empty())
            {
                break;
            }
            leftMost = S.pop();
            visit(leftMost.val, res);
            root = leftMost.right;
        }
    }

    private void visit(int val, List<Integer> res)
    {
        if (isFirst)
        {
            lastVal = val;
            isFirst = false;
        }

        if (val == lastVal)
        {
            ++count;
        }
        else
        {
            record(lastVal, res);
            lastVal = val;
            count = 1;
        }
    }

    private void record(int val, List<Integer> res)
    {
        if (count == maxCount)
        {
            res.add(val);
        }
        else if (count > maxCount)
        {
            res.clear();
            res.add(val);
            maxCount = count;
        }
    }
}