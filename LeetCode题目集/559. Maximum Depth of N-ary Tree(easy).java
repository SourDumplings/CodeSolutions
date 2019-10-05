/*
 * @Autor: SourDumplings
 * @Date: 2019-10-04 19:56:24
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
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
    public int maxDepth(Node root)
    {
        if (root == null)
        {
            return 0;
        }
        int maxD = 0;
        for (Node c : root.children)
        {
            int cd = maxDepth(c);
            if (cd > maxD)
            {
                maxD = cd;
            }
        }
        return maxD + 1;
    }
}