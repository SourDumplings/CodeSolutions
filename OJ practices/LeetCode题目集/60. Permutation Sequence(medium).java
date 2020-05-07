/**
 * @Author: SourDumplings
 * @Date: 2020-05-07 15:47:53
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/permutation-sequence/
 * 
 * 在n个数字的排列中，根据手动排列的习惯，先固定第一个位置的数字，还剩下最多(n-1)!种排列，
 * 再由放到第一个位置的数字原先的位置i(从左往右第i个)的不同，表示跳过了i(n-1)种排列。
 * 要找到第k个排列，先由i = k/(n-1)得出应该移到第一个位置的数字索引，并由k = k%(n - 1)更新k.
 * 这样，我们可以从左往右遍历原先字符串的最小排列，
 * 每一次找到应该放在左边第一个位置的数字，将其添加到结果字符串中，
 * 并从原字符串中删除，然后对剩下的字符串重复这一操作，直到k==0。
 * 此外由于字符串最初的状态就是第１个排列，所以要将输入的k先减一。
 */


class Solution
{
    public String getPermutation(int n, int k)
    {
        int[] fac = {0, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
        StringBuilder res = new StringBuilder();
        String s = "123456789".substring(0, n);
        --k;
        while (k > 0)
        {
            int i = k / fac[n - 1];
            String temp = null;
            res.append(s.charAt(i));
            temp = s.substring(0, i) + s.substring(i + 1);
            s = temp;
            k %= fac[n - 1];
            --n;
        }
        res.append(s);
        return res.toString();
    }
}