/*
 * @Author: SourDumplings
 * @Date: 2020-09-21 18:40:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node-ii/
 */

class Solution
{
    Node nodeOfNextL, leftmostOfNextL;

    public void processChild(Node childNode)
    {

        if (childNode != null)
        {

            if (this.nodeOfNextL != null)
            {
                this.nodeOfNextL.next = childNode;

            }
            else
            {

                this.leftmostOfNextL = childNode;
            }

            this.nodeOfNextL = childNode;
        }
    }

    public Node connect(Node root)
    {

        if (root == null)
        {
            return root;
        }

        this.leftmostOfNextL = root;
        Node nodeOfThisL = null;
        root.next = null;

        while (this.leftmostOfNextL != null)
        {
            this.nodeOfNextL = null;
            nodeOfThisL = this.leftmostOfNextL;
            
            this.leftmostOfNextL = null;

            while (nodeOfThisL != null)
            {
                this.processChild(nodeOfThisL.left);
                this.processChild(nodeOfThisL.right);
                nodeOfThisL = nodeOfThisL.next;
            }
        }

        return root;
    }

}
