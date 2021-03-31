/*
 * @Author: SourDumplings
 * @Date: 2021-03-31 10:16:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/verify-preorder-serialization-of-a-binary-tree/
 */

class Solution
{
public:
    bool isValidSerialization(string preorder)
    {
        int l = preorder.length();
        stack<int> S; // 存放槽位的栈
        bool isD = false;
        bool first = true;
        for (int i = 0; i < l; ++i)
        {
            // 扫描数字
            while (isdigit(preorder[i]))
            {
                ++i;
                isD = true;
            }
            if (isD)
            {
                --i;
            }
            // 根结点特殊处理
            if (first)
            {
                first = false;
                if (isD)
                {
                    S.push(2);
                }
                else
                {
                    return l == 1;
                }
            }
            else if (preorder[i] != ',')
            {
                if (S.empty())
                {
                    return false;
                }
                // 占据一个槽位
                --S.top();
                if (S.top() == 0)
                {
                    S.pop();
                }
                if (isD)
                {
                    // 数字则意味着非空结点，还可以放两个槽位
                    S.push(2);
                }
            }
            isD = false;
        }
        return S.empty();
    }
};