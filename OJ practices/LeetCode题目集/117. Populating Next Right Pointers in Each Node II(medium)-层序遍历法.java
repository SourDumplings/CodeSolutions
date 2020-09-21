/*
 * @Author: SourDumplings
 * @Date: 2020-09-21 09:22:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/
 */

class Solution
{
    public Node connect(Node root)
    {
        Queue<Node> q = new LinkedList<Node>();
        if (root == null)
        {
            return null;
        }
        q.add(root);
        while (!q.isEmpty())
        {
            List<Node> list = new ArrayList<Node>();
            while (!q.isEmpty())
            {
                list.add(q.remove());
            }
            int s = list.size();
            for (int i = 0; i < s - 1; i++)
            {
                Node thisNode = list.get(i);
                thisNode.next = list.get(i + 1);
                if (thisNode.left != null)
                {
                    q.add(thisNode.left);
                }
                if (thisNode.right != null)
                {
                    q.add(thisNode.right);
                }
            }
            Node lastNode = list.get(s - 1);
            list.get(s - 1).next = null;
            if (lastNode.left != null)
            {
                q.add(lastNode.left);
            }
            if (lastNode.right != null)
            {
                q.add(lastNode.right);
            }
        }
        return root;
    }
}
