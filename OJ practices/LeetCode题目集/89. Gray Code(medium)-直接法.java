/*
 * @Author: SourDumplings
 * @Date: 2020-08-18 17:55:41
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/gray-code/
 * 
 * 参考：https://blog.csdn.net/u012501459/article/details/46790683
 * 格雷码公式：i ^ i >> 1
 */

class Solution
{
    public List<Integer> grayCode(int n)
    {
        List<Integer> res = new ArrayList<>();
        int max = 1 << n;
        for (int i = 0; i < max; i++)
        {
            res.add(i ^ i >> 1);
        }
        return res;
    }
}

