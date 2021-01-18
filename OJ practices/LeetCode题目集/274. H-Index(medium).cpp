/*
 * @Author: SourDumplings
 * @Date: 2021-01-18 20:15:44
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/h-index/
 * 
 * 想象一个直方图
 * 参考：https://leetcode-cn.com/problems/h-index/solution/hzhi-shu-by-leetcode/
 */

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int i;
        for (i = 0; i < n; ++i)
        {
            if (citations[n - i - 1] <= i)
            {
                break;
            }
        }
        return i;
    }
};