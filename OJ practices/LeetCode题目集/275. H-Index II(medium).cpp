/*
 * @Author: SourDumplings
 * @Date: 2021-01-19 10:45:08
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/h-index-ii/
 */

class Solution
{
public:
    int hIndex(vector<int> &citations)
    {
        int n = citations.size();
        sort(citations.begin(), citations.end());
        int b = 0, e = n;
        while (b < e)
        {
            int mi = (b + e) / 2;
            if (citations[n - mi - 1] <= mi)
            {
                if (mi > 0 && n - mi >= 0 && citations[n - mi] > mi - 1)
                {
                    b = mi;
                    break;
                }
                else
                {
                    e = mi;
                }
            }
            else
            {
                b = mi + 1;
            }
        }

        return b;
    }
};