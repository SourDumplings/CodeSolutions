/*
 * @Autor: SourDumplings
 * @Date: 2019-09-25 09:42:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
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
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> res;
        if (!root)
        {
            return res;
        }
        doLevelOrder(res, root);
        return res;
    }

    void doLevelOrder(vector<vector<int>> &res, Node *root)
    {
        queue<Node *> thisQ;
        thisQ.push(root);
        while (!thisQ.empty())
        {
            vector<int> thisLevel;
            queue<Node *> nextQ;
            while (!thisQ.empty())
            {
                Node *p = thisQ.front();
                thisQ.pop();
                thisLevel.push_back(p->val);
                for (Node *c : p->children)
                {
                    nextQ.push(c);
                }
            }
            thisQ = std::move(nextQ);
            res.push_back(thisLevel);
        }
    }
};