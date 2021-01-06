/*
 * @Author: SourDumplings
 * @Date: 2021-01-06 09:13:52
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/rectangle-area/
 * 
 * 
参考：https://leetcode-cn.com/problems/rectangle-area/solution/jian-dan-de-kao-lu-by-powcai/

首先，我们调整两个矩形，让第一个矩形是靠最左边的；
其次，先考虑没有重叠的情况
最后， 要考虑重叠的情况，因为一定有重叠，所以可以找到上下左右边界
上边界，取两个矩形的上边界的最小值
下边界，取两个矩形的下边界的最大值
左边界，取两个矩形的左边界的最大值
右边界，取两个矩形的右边界的最小值
 */

class Solution
{
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H)
    {
        if (E < A)
        {
            return computeArea(E, F, G, H, A, B, C, D);
        }

        long long sum = static_cast<long long>((C - A) * (D - B))
            + static_cast<long long>((G - E) * (H - F));
        if (C < E || D < F || H < B)
        {
            // 无重叠情况
            return sum;
        }

        int overlapSum = (min(D, H) - max(B, F)) * (min(C, G) - max(A, E));
        return sum - overlapSum;
    }
};