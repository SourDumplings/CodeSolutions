import java.util.List;

/*
 * @Autor: SourDumplings
 * @Date: 2019-10-30 09:38:28
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/self-dividing-numbers/
 */

class Solution
{
    public List<Integer> selfDividingNumbers(int left, int right)
    {
        List<Integer> res = new ArrayList<>();
        for (int i = left; i <= right; ++i)
        {
            if (isOK(i))
            {
                res.add(i);
            }
        }
        return res;
    }

    boolean isOK(int num)
    {
        int temp = num;
        int d;
        do
        {
            d = temp % 10;
            if (d == 0 || num % d != 0)
            {
                return false;
            }
            temp /= 10;
        }
        while (temp > 0);
        return true;
    }
}