/*
 * @Autor: SourDumplings
 * @Date: 2019-10-04 18:56:05
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/quad-tree-intersection/
 */

/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {}

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/
class Solution
{
public:
    Node *intersect(Node *quadTree1, Node *quadTree2)
    {
        bool isLeaf = false, val = false;
        Node *topLeft = nullptr, *topRight = nullptr, *bottomLeft = nullptr,
             *bottomRight = nullptr;
        if (quadTree1->isLeaf)
        {
            if (quadTree2->isLeaf)
            {
                isLeaf = true;
                val = quadTree1->val || quadTree2->val;
            }
            else
            {
                topLeft = intersect(quadTree1, quadTree2->topLeft);
                topRight = intersect(quadTree1, quadTree2->topRight);
                bottomLeft = intersect(quadTree1, quadTree2->bottomLeft);
                bottomRight = intersect(quadTree1, quadTree2->bottomRight);
            }
        }
        else
        {
            if (quadTree2->isLeaf)
            {
                topLeft = intersect(quadTree2, quadTree1->topLeft);
                topRight = intersect(quadTree2, quadTree1->topRight);
                bottomLeft = intersect(quadTree2, quadTree1->bottomLeft);
                bottomRight = intersect(quadTree2, quadTree1->bottomRight);
            }
            else
            {
                topLeft = intersect(quadTree1->topLeft, quadTree2->topLeft);
                topRight = intersect(quadTree1->topRight, quadTree2->topRight);
                bottomLeft = intersect(quadTree1->bottomLeft, quadTree2->bottomLeft);
                bottomRight = intersect(quadTree1->bottomRight, quadTree2->bottomRight);
            }
        }

        if (topLeft && topLeft->isLeaf && topRight->isLeaf && bottomLeft->isLeaf && bottomRight->isLeaf && topLeft->val == topRight->val &&
            topLeft->val == bottomLeft->val && topLeft->val == bottomRight->val)
        {
            isLeaf = true;
            val = topLeft->val;
            topLeft = topRight = bottomLeft = bottomRight = nullptr;
        }

        return new Node(val, isLeaf, topLeft, topRight, bottomLeft, bottomRight);
    }
};