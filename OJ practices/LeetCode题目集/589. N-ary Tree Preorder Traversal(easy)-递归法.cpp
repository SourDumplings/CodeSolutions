/*
 * @Author: SourDumplings
 * @Date: 2019-10-06 15:33:27
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/n-ary-tree-preorder-traversal/
 */

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> res;
        doPreOrder(root, res);
        return res;
    }

    void doPreOrder(Node *node, vector<int> &res)
    {
        if (node)
        {
            res.push_back(node->val);
            for (auto &&c : node->children)
            {
                doPreOrder(c, res);
            }
        }
    }
};