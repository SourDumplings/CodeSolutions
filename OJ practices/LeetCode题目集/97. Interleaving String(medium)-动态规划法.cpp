/*
 * @Author: SourDumplings
 * @Date: 2021-06-05 08:11:51
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/interleaving-string/
 * 
 * 参考：https://leetcode-cn.com/problems/interleaving-string/solution/jiao-cuo-zi-fu-chuan-by-leetcode-solution/
 * 
 * 定义 f[i][j] 表示 s3[0:i+j] 是否能够通过 s1[0:i+1] 和 s2[0:j+1] 交织得到
 * 对于f[i][j]，如果 s3[i+j-1] == s1[i-1]，则看f[i-1][j]是否是true
 */

class Solution
{
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
        if (l3 != l1 + l2)
        {
            return false;
        }
        auto f = vector<vector<int> >(s1.size() + 1,
                                      vector<int>(s2.size() + 1, false));
        f[0][0] = true;
        for (int i = 0; i <= l1; ++i)
        {
            for (int j = 0; j <= l2; ++j)
            {
                int p = i + j - 1;
                if (i > 0)
                {
                    f[i][j] |= (f[i - 1][j] && s1[i - 1] == s3[p]);
                }
                if (j > 0)
                {
                    f[i][j] |= (f[i][j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }
        return f[l1][l2];
    }
};