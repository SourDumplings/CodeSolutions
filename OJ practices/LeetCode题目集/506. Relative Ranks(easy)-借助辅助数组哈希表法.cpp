/*
 * @Author: SourDumplings
 * @Date: 2019-09-28 15:39:58
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/relative-ranks/
 */

class Solution
{
public:
    vector<string> findRelativeRanks(vector<int> &nums)
    {
        vector<int> temp(nums);
        sort(temp.rbegin(), temp.rend());
        vector<string> res;
        int n = temp.size();
        unordered_map<int, int> m;
        for (int i = 0; i < n; i++)
        {
            m[temp[i]] = i;
        }

        for (int i = 0; i < n; i++)
        {
            int r = m[nums[i]];
            switch (r)
            {
            case 0:
                res.push_back("Gold Medal");
                break;
            case 1:
                res.push_back("Silver Medal");
                break;
            case 2:
                res.push_back("Bronze Medal");
                break;
            default:
                res.push_back(to_string(r + 1));
            }
        }
        return res;
    }
};