/*
 * @Author: SourDumplings
 * @Date: 2020-09-07 09:35:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/path-sum-ii/
 */

class Solution
{
    private List<List<Integer>> res = new ArrayList<>();
    private List<Integer> thisPath = new ArrayList<>();
    private int thisSum = 0;

    public List<List<Integer>> pathSum(TreeNode root, int sum)
    {
        if (root != null)
        {
            dfs(root, sum);
        }
        return res;
    }

    private void dfs(TreeNode root, int sum)
    {
        thisSum += root.val;
        thisPath.add(root.val);
        if (thisSum == sum && root.left == null && root.right == null)
        {
            res.add(new ArrayList<>(thisPath));
        }
        else
        {
            if (root.left != null)
            {
                dfs(root.left, sum);
            }
            if (root.right != null)
            {
                dfs(root.right, sum);
            }
        }
        thisPath.remove(thisPath.size() - 1);
        thisSum -= root.val;
    }
}


