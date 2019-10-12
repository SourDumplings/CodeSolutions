import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/*
 * @Autor: SourDumplings
 * @Date: 2019-10-06 15:37:32
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/n-ary-tree-preorder-traversal/
 * 
 * 这个迭代法就是把递归的过程模拟了一下
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
    public List<Integer> preorder(Node root)
    {
        List<Integer> res = new ArrayList<>();
        Stack<Node> S = new Stack<>();
        if (root != null)
        {
            S.push(root);
            while (!S.isEmpty())
            {
                Node node = S.pop();
                res.add(node.val);
                int lc = node.children.size();
                for (int i = lc - 1; i >= 0; i--)
                {
                    Node c = node.children.get(i);
                    if (c != null)
                    {
                        S.push(c);
                    }
                }
            }
        }
        return res;
    }
}