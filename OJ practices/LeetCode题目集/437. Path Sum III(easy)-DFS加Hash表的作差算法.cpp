/*
 * @Author: SourDumplings
 * @Date: 2019-09-25 16:50:53
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/path-sum-iii/
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 * 
 * 利用哈希表加DFS算法，时间复杂度为O(n)
 * 既然不一定从root作为起点，那么我们可以利用作差的思想间接变换起点
 * 思路就是记录下从root走到当前结点时所累积的值的路径数，比如：
 *          10
           /  \
          5   -3
         / \    \
      ->3   2   11
       / \   \
      3  -2   1
 * 假设我们需要的sum是8，遍历到了箭头指向的结点3，此时当前值为18，
 * 那么我们只需要知道从根结点到当前结点的路径上，有没有路径值为18 - 8 = 10的路径，加上它的条数即可
 * 这样就间接的加上了以这个结点3为终点的路径值为8的所有路径
 */
class Solution
{
public:
    int pathSum(TreeNode *root, int sum)
    {
        unordered_map<int, int> path_num;
        int res = 0;
        path_num[0] = 1;
        dfs(root, 0, path_num, sum, res);
        return res;
    }

    void dfs(TreeNode *Node, int thisV, unordered_map<int, int> &path_num, int sum, int &res)
    {
        if (!Node)
        {
            return;
        }
        thisV += Node->val;
        res += path_num[thisV - sum];
        ++path_num[thisV];
        dfs(Node->left, thisV, path_num, sum, res);
        dfs(Node->right, thisV, path_num, sum, res);
        --path_num[thisV];
    }
};