/*
 * @Autor: SourDumplings
 * @Date: 2019-10-06 15:53:04
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/n-ary-tree-preorder-traversal/
 * 
 * 一路向左访问，有右儿子就压栈（逆序），然后弹出栈顶元素访问
 */

import java.util.ArrayList;
import java.util.List;
import java.util.Stack;

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
        while (true)
        {
            Node leftMost = root;
            while (leftMost != null)
            {
                res.add(leftMost.val);
                if (leftMost.children.isEmpty())
                {
                    break;
                }
                else
                {
                    int lc = leftMost.children.size();
                    for (int i = lc - 1; i > 0; i--)
                    {
                        Node c = leftMost.children.get(i);
                        S.push(c);
                    }
                    leftMost = leftMost.children.remove(0);
                }
            }
            if (S.isEmpty())
            {
                break;
            }
            root = S.pop();
        }
        return res;
    }
}