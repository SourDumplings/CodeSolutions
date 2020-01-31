import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-25 11:27:52
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
 */

/*
// Definition for a Node.
class Node {
  public int val;
  public List<Node> children;

  public Node() {}

  public Node(int _val,List<Node> _children) {
      val = _val;
      children = _children;
  }
};
*/
class Solution
{
    public List<List<Integer>> levelOrder(Node root)
    {
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        if (root == null)
        {
            return res;
        }
        doLevelOrder(res, root, 1);
        return res;
    }

    public void doLevelOrder(List<List<Integer>> res, Node root, int level)
    {
        if (res.size() < level)
        {
            res.add(new ArrayList<Integer>());
        }
        res.get(level - 1).add(root.val);
        for (Node c : root.children)
        {
            doLevelOrder(res, c, level + 1);
        }
    }
}