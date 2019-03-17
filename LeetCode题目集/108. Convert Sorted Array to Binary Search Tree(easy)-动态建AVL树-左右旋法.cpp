/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * @Date: 2019-03-05 11:56:35
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
                        single_left_rotation(root);
                    }
                    else
                    {
                        double_left_right_rotation(root);
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
                        single_right_rotation(root);
                    }
                    else
                    {
                        double_right_left_rotation(root);
                    }
                }
            }
        }
        return root;
    }

    void single_left_rotation(TreeNode *&A)
    {
        TreeNode *B = A->left;
        A->left = B->left;
        B->right = A;
        A = B;
    }
    void single_right_rotation(TreeNode *&A)
    {
        TreeNode *B = A->right;
        A->right = B->left;
        B->left = A;
        A = B;
    }
    void double_left_right_rotation(TreeNode *&A)
    {
        single_right_rotation(A->left);
        single_left_rotation(A);
    }
    void double_right_left_rotation(TreeNode *&A)
    {
        single_left_rotation(A->left);
        single_right_rotation(A);
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