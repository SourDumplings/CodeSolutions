/*
 * @Author: SourDumplings
 * @Date: 2019-11-05 09:56:06
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/reach-a-number/
 * 
 * 对于target正负是对称的，故先取绝对值
 * 累加k，找到刚好使得和sum不小于target
 * 如果sum == target那么结果就是k
 * 如果sum > target，将二者作差得到d，必有d < k
 * 如果d是偶数，那么在1~k中肯定能够找到一个值将其符号改为负即可满足sum == target
 * 如果d是奇数，这个是不行的，因为无论改变1~k中谁的负号也没用，因为对于sum的减少一定是偶数的
 * 那么需要再来一个数k + 1或者两个数把d搞成偶数才行
 */

class Solution
{
    public int reachNumber(int target)
    {
        target = Math.abs(target);
        int k = 0;
        int sum = 0;
        while (sum < target)
        {
            sum += ++k;
        }
        int d = sum - target;
        return d % 2 == 0 ? k : k + 1 + k % 2;
    }
}