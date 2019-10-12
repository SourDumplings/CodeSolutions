import java.util.BitSet;

/*
 * @Autor: SourDumplings
 * @Date: 2019-10-11 20:14:59
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/set-mismatch/
 */

class Solution
{
    public int[] findErrorNums(int[] nums)
    {
        int n = nums.length;
        BitSet b = new BitSet(n);
        int[] res = new int[2];
        for (int i : nums)
        {
            if (b.get(i - 1))
            {
                res[0] = i;
            }
            else
            {
                b.set(i - 1);
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (!b.get(i))
            {
                res[1] = i + 1;
                break;
            }
        }
        return res;
    }
}