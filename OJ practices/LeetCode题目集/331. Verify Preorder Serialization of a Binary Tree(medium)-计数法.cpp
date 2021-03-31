/*
 * @Author: SourDumplings
 * @Date: 2021-03-31 11:22:34
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
        int slotNum = 0;
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
                    slotNum += 2;
                }
                else
                {
                    return l == 1;
                }
            }
            else if (preorder[i] != ',')
            {
                if (slotNum == 0)
                {
                    return false;
                }
                // 占据一个槽位
                --slotNum;
                if (isD)
                {
                    // 数字则意味着非空结点，还可以放两个槽位
                    slotNum += 2;
                }
            }
            isD = false;
        }
        return slotNum == 0;
    }
};