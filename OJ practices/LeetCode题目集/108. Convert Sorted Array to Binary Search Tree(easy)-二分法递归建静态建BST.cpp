/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
 * @Date: 2019-03-05 13:32:32
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
        if (nums.empty())
        {
            return nullptr;
        }
        int n = nums.size();
        int mid = n / 2;
        TreeNode *root = new TreeNode(nums[mid]);
        vector<int> left, right;
        for (int i = 0; i < mid; i++)
        {
            left.push_back(nums[i]);
        }
        for (int i = mid + 1; i < n; i++)
        {
            right.push_back(nums[i]);
        }
        root->left = sortedArrayToBST(left);
        root->right = sortedArrayToBST(right);
        return root;
    }
};