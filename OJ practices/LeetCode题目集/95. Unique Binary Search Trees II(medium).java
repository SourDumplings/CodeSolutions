/*
 * @Author: SourDumplings
 * @Date: 2020-08-30 08:55:53
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/unique-binary-search-trees-ii/
 */

class Solution
{
    public List<TreeNode> generateTrees(int n)
    {
        if (n != 0)
        {
            return generateTrees(1, n);
        }
        else
        {
            return new ArrayList<>();
        }
    }

    private List<TreeNode> generateTrees(int s, int l)
    {
        List<TreeNode> trees = new ArrayList<>();
        if (s <= l)
        {
            for (int i = s; i <= l; i++)
            {
                List<TreeNode> leftTrees = generateTrees(s, i - 1);
                List<TreeNode> rightTrees = generateTrees(i + 1, l);
                for (TreeNode rightTree : rightTrees)
                {
                    for (TreeNode leftTree : leftTrees)
                    {
                        TreeNode node = new TreeNode(i, leftTree, rightTree);
                        trees.add(node);
                    }
                }
            }
        }
        else
        {
            trees.add(null);
        }
        return trees;
    }
}