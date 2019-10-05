/*
 * @Autor: SourDumplings
 * @Date: 2019-10-04 19:52:53
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/maximum-depth-of-n-ary-tree/
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
    int maxDepth(Node *root)
    {
        if (!root)
        {
            return 0;
        }
        int maxD = 0;
        for (auto &&c : root->children)
        {
            int dc = maxDepth(c);
            if (dc > maxD)
            {
                maxD = dc;
            }
        }
        return maxD + 1;
    }
};