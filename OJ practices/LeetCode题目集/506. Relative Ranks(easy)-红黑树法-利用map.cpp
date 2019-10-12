/*
 * @Autor: SourDumplings
 * @Date: 2019-09-28 16:04:01
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/relative-ranks/
 */

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {
        map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            m[nums[i]] = i;
        }
        vector<string> res;
        res.resize(n);
        int r = n - 1;
        for (auto &&p : m)
        {
            int i = p.second;
            switch (r)
            {
            case 0:
                res[i] = "Gold Medal";
                break;
            case 1:
                res[i] = "Silver Medal";
                break;
            case 2:
                res[i] = "Bronze Medal";
                break;

            default:
                res[i] = to_string(r + 1);
                break;
            }
            --r;
        }

        return res;
    }
};