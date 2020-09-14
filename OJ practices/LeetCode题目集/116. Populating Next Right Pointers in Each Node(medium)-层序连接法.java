/*
 * @Author: SourDumplings
 * @Date: 2020-09-14 17:47:35
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/
 */

class Solution
{
    public Node connect(Node root)
    {

        if (root != null)
        {
            Node leftMost = root;
            leftMost.next = null;

            while (leftMost != null)
            {
                Node head = leftMost;

                while (head != null)
                {
                    if (head.left != null)
                    {
                        head.left.next = head.right;
                    }

                    if (head.right != null)
                    {
                        if (head.next != null)
                        {
                            head.right.next = head.next.left;
                        }
                        else
                        {
                            head.right.next = null;
                        }
                    }

                    head = head.next;
                }

                leftMost = leftMost.left;
            }
        }

        return root;
    }
}

