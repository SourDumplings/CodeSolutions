/*
 * @Author: SourDumplings
 * @Date: 2020-09-14 17:09:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
 */

class Solution
{
    public Node connect(Node root)
    {
        Queue<Node> q = new LinkedList<>();
        if (root != null)
        {
            q.add(root);
        }
        while (!q.isEmpty())
        {
            List<Node> thisLevel = new ArrayList<>();
            while (!q.isEmpty())
            {
                thisLevel.add(q.remove());
            }
            int l = thisLevel.size();
            if (l == 0)
            {
                break;
            }
            for (int i = 0; i < l - 1; i++)
            {
                Node thisNode = thisLevel.get(i);
                thisNode.next = thisLevel.get(i + 1);
                if (thisNode.left != null)
                {
                    q.add(thisNode.left);
                }
                if (thisNode.right != null)
                {
                    q.add(thisNode.right);
                }
            }
            Node lastNode = thisLevel.get(l - 1);
            lastNode.next = null;
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