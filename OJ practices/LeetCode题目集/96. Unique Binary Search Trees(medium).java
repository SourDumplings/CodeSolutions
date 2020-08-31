/*
 * @Author: SourDumplings
 * @Date: 2020-08-31 09:41:34
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/unique-binary-search-trees/
 */

class Solution
{
    private int[] treeNum;
    
    public int numTrees(int n)
    {
        treeNum = new int[n + 1];
        Arrays.fill(treeNum, -1);
        treeNum[0] = 0;
        return numTrees(1, n);
    }

    private int numTrees(int s, int l)
    {
        int res = 0;
        if (s <= l)
        {
            if (treeNum[l - s + 1] != -1)
            {
                return treeNum[l - s + 1];
            }
            for (int i = s; i <= l; i++)
            {
                int leftTreeNum = numTrees(s, i - 1);
                int rightTreeNum = numTrees(i + 1, l);
                res += leftTreeNum * rightTreeNum;
            }
        }
        else
        {
            return 1;
        }
        treeNum[l - s + 1] = res;
        return res;
    }
}
