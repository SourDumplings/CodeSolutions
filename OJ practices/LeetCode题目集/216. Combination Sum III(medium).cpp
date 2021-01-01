/*
 * @Author: SourDumplings
 * @Date: 2021-01-01 11:33:39
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/combination-sum-iii/
 */

class Solution
{
private:
    vector<shared_ptr<vector<int>>> help(int s, int k, int n)
    {
        vector<shared_ptr<vector<int>>> res;
        if (k > 0)
        {
            if (k == 1)
            {
                if (s <= n && n <= 9)
                {
                    vector<int> *p = new vector<int>({n});
                    res.push_back(shared_ptr<vector<int>>(p));
                }
            }
            else
            {
                for (int i = s; i <= n; ++i)
                {
                    vector<shared_ptr<vector<int>>> temp = help(i + 1, k - 1, n - i);
                    for (auto pv : temp)
                    {
                        pv->push_back(i);
                        res.push_back(pv);
                    }
                }
            }
        }
        return res;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n)
    {
        vector<shared_ptr<vector<int>>> temp = help(1, k, n);
        vector<vector<int>> res;
        for (auto pv : temp)
        {
            res.push_back(*pv);
        }
        return res;
    }
};