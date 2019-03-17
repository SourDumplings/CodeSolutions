/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * @Date: 2019-03-05 12:24:07
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
  public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root = nullptr;
        for (int num : nums)
        {
            insert(root, num);
        }
        return root;
    }

    void *insert(TreeNode *&root, int num)
    {
        if (root == nullptr)
        {
            root = new TreeNode(num);
        }
        else
        {
            if (num < root->val)
            {
                insert(root->left, num);
                if (get_height(root->left) - get_height(root->right) >= 2)
                {
                    if (num < root->left->val)
                    {
                        root = reconstruct34(root->left->left, root->left, root,
                                             root->left->left->left, root->left->left->right,
                                             root->left->right, root->right);
                    }
                    else
                    {
                        root = reconstruct34(root->left, root->left->right, root,
                                             root->left->left, root->left->right->left,
                                             root->left->right->right, root->right);
                    }
                }
            }
            if (num > root->val)
            {
                insert(root->right, num);
                if (get_height(root->left) - get_height(root->right) <= -2)
                {
                    if (num > root->right->val)
                    {
                        root = reconstruct34(root, root->right, root->right->right,
                                             root->left, root->right->left, root->right->right->left,
                                             root->right->right->right);
                    }
                    else
                    {
                        root = reconstruct34(root, root->right->left, root->right,
                                             root->left, root->right->left->left, root->right->left->right,
                                             root->right->right);
                    }
                }
            }
        }
        return root;
    }
    TreeNode *reconstruct34(TreeNode *A, TreeNode *B, TreeNode *C,
                            TreeNode *T1, TreeNode *T2, TreeNode *T3, TreeNode *T4)
    {
        B->left = A;
        B->right = C;
        A->left = T1;
        A->right = T2;
        C->left = T3;
        C->right = T4;
        return B;
    }
    int get_height(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        else
        {
            return max(get_height(root->left), get_height(root->right)) + 1;
        }
    }
};