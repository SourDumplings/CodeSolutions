/*
 * @Author: SourDumplings
 * @Date: 2021-03-20 09:42:17
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/super-ugly-number/
 
简单分析过程：
1.为每个质因数建立一个指针，记录与该质数相乘的丑数的索引，
然后在这几个质因数运算的结果中，找出个最小的，
然后匹配这个数是由哪个质因数算出来的，把它的指针值+1。
2.这道题的套路也差不多。只不过，因为我们这次是需要把计算出来的丑数再次和primes里面的质因数结合，
算出新的丑数。算出来的丑数放在一个dp数组里。
3.所以，现在要做的事，怎么能知道每个质因数已经和dp中哪个位置的丑数进行了结合，
下一个要结合的位置在哪。就需要建立一个index数组，
用来存放每个质因数下一个将要结合的dp的下标，这个下标是从0开始的，
每结合一次就+1。
extra：就是如果出现不同的质因数相乘，乘出来的结果是相同的，是重复的丑数，这个时候该怎么办呢：
应该把这几个质因数下一个要结合的dp下标都加1。因为只把其中一个+1的话，
下一次计算的丑数一定会是刚才这个重复的丑数，你的结果中就会有很多重复的数，
所以，全都加1的话就会把这个重复数给过滤掉了。

作者：xiao-xin-28
链接：https://leetcode-cn.com/problems/super-ugly-number/solution/javazui-rong-yi-li-jie-de-dong-tai-gui-hua-fen-xi-/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */

class Solution
{
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
//        nums[i] 保存的是第i个超级丑数
        vector<int> nums(1, 1);
        int k = primes.size();
//        index[i] 表示的是primes里面的第i个数下一个将要相乘的数在dp中的位置
        vector<int> index(k, 0);
        for (int i = 0; i < n; ++i)
        {
            int minValue = INT32_MAX;
            for (int j = 0; j < k; ++j)
            {
                minValue = min(minValue, primes[j] * nums[index[j]]);
            }
            // 将获得的最小数加入超级丑数列表
            nums.push_back(minValue);
/*             那个素数要乘以的nums的坐标index要加1，向后推一个位
             即该素数要与下一个超级丑数相乘了
             如果存在重复的值，也就是说不同的质因数相乘，得出来相同的结果了，
             我们就把这几个位置都+1，这样就可以避免出现重复的值了。
             假如你找到了对应的素数的index，把它加1之后就break掉，那么后面的数也可以算出这个结果，
             下次循环的时候，势必会把这个重复的数当成下一个dp，因为这个数肯定要比下一个丑数小
             所以我们在for循环中不要加break；*/
            for (int l = 0; l < k; ++l)
            {
                if (primes[l] * nums[index[l]] == minValue)
                {
                    ++index[l];
                }
            }
        }
        return nums[n - 1];
    }
};

