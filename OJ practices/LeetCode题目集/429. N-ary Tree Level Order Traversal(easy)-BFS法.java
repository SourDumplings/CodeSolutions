import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

/*
 * @Author: SourDumplings
 * @Date: 2019-09-25 11:10:59
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
        doLevelOrder(res, root);
        return res;
    }

    public void doLevelOrder(List<List<Integer>> res, Node root)
    {
        Queue<Node> thisQ = new LinkedList<>();
        thisQ.add(root);
        while (!thisQ.isEmpty())
        {
            Queue<Node> nextQ = new LinkedList<>();
            List<Integer> thisLevel = new ArrayList<>();
            while (!thisQ.isEmpty())
            {
                Node p = thisQ.poll();
                thisLevel.add(p.val);
                for (Node c : p.children)
                {
                    nextQ.add(c);
                }
            }

            res.add(thisLevel);
            thisQ = nextQ;
        }
    }
}