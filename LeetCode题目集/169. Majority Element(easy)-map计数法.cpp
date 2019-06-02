/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: 
 * @Date: 2019-04-27 21:03:44
 */

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        unordered_map<int, int> umap;
        int res = nums[0], maxTime = 0;
        for (auto &i : nums)
        {
            ++umap[i];
            if (umap[i] > maxTime)
            {
                maxTime = umap[i];
                res = i;
            }
        }
        return res;
    }
};