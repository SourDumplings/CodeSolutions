import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

/*
 * @Autor: SourDumplings
 * @Date: 2019-10-07 10:36:12
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/n-ary-tree-postorder-traversal/
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
    public List<Integer> postorder(Node root)
    {
        Stack<Node> S = new Stack<>();
        Node p = root;
        List<Integer> res = new ArrayList<>();
        while (p != null || !S.isEmpty())
        {
            if (p != null)
            {
                S.push(p);
                if (!p.children.isEmpty())
                {
                    p = p.children.remove(0);
                }
                else
                {
                    p = null;
                }
            }
            else
            {
                p = S.peek();
                if (!p.children.isEmpty())
                {
                    p = p.children.remove(0);
                    S.push(p);
                    if (p.children.isEmpty())
                    {
                        p = null;
                    }
                    else
                    {
                        p = p.children.remove(0);
                    }
                }
                else
                {
                    res.add(p.val);
                    S.pop();
                    p = null;
                }
            }
        }
        return res;
    }
}