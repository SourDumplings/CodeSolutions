/*
 * @Author: SourDumplings
 * @Date: 2021-07-06 11:51:21
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/recover-binary-search-tree/
 * 
 * 参考：https://leetcode-cn.com/problems/recover-binary-search-tree/solution/san-chong-jie-fa-xiang-xi-tu-jie-99-hui-fu-er-cha-/
 */

class Solution
{
public:
    void recoverTree(TreeNode *root)
    {
        TreeNode *x = nullptr, *y = nullptr, *pred = nullptr,
            *tmp = nullptr;

        while (root != nullptr)
        {
            if (root->left != nullptr)
            {
                // tmp 节点就是当前 root 节点向左走一步，然后一直向右走至无法走为止
                tmp = root->left;
                while (tmp->right != nullptr
                    && tmp->right != root)
                {
                    tmp = tmp->right;
                }

                // 让 tmp 的右指针指向 root，继续遍历左子树
                // 这样利用了原本为空的 tmp 的右孩子指针存储，便省去了堆栈
                if (tmp->right == nullptr)
                {
                    tmp->right = root;
                    root = root->left;
                }
                // 此时必有 tmp->right == root
                // 说明左子树已经访问完了，我们需要断开链接
                else
                {
                    if (pred != nullptr && root->val < pred->val)
                    {
                        y = root;
                        if (x == nullptr)
                        {
                            x = pred;
                        }
                    }
                    pred = root;

                    tmp->right = nullptr;
                    root = root->right;
                }
            }
            // 如果没有左孩子，则直接访问右孩子
            else
            {
                if (pred != nullptr && root->val < pred->val)
                {
                    y = root;
                    if (x == nullptr)
                    {
                        x = pred;
                    }
                }
                pred = root;
                root = root->right;
            }
        }
        swap(x->val, y->val);
    }
};