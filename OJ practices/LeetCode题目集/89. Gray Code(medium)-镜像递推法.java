/*
 * @Author: SourDumplings
 * @Date: 2020-08-18 17:55:41
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/gray-code/
 * 
 * 参考：https://blog.csdn.net/u012501459/article/details/46790683
 * n = 1:
 *  0
 *  1
 * 
 * n = 2:
 *  00
 *  01
 *  11
 *  10
 * 
 * n = 3:
 *  000
 *  001
 *  011
 *  010
 *  100
 *  101
 *  111
 *  110
 *  
 * 可以发现，n = k + 1 时的结果正好是 n = k 的结果最前面补 0 与最前面补 1 的数集。
 */

class Solution
{
    public List<Integer> grayCode(int n)
    {
        List<Integer> res = new ArrayList<>();
        res.add(0);
        for (int i = 0; i < n; i++)
        {
            for (int j = res.size() - 1; j >= 0; j--)
            {
                res.add((1 << i) + res.get(j));
            }
        }
        return res;
    }
}
