/*
 * @Author: SourDumplings
 * @Date: 2020-10-10 17:08:41
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/clone-graph/
 */

class Solution
{
    private Map<Node, Node> map = new HashMap<>();

    public Node cloneGraph(Node node)
    {
        if (node == null)
        {
            return null;
        }
        else if (map.containsKey(node))
        {
            return map.get(node);
        }
        else
        {
            Node newNode = new Node(node.val);
            map.put(node, newNode);
            List<Node> neighbors = node.neighbors;
            int n = neighbors.size();
            for (int i = 0; i < n; i++)
            {
                Node newNeighbor = cloneGraph(neighbors.get(i));
                newNode.neighbors.add(newNeighbor);
            }
            return newNode;
        }

    }
}