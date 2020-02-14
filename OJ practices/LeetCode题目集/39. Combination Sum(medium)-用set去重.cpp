/*
 * @Author: SourDumplings
 * @Date: 2020-02-14 10:21:30
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/combination-sum/
 * 
 * 对于每次的结果序列，每当获得的结果将其排序加入一个临时的 set 中进行去重.
 */

class Solution
{
private:
    set<vector<int>> tempRes;
    vector<int> thisList;
    int thisSum = 0;

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> res;
        sort(candidates.begin(), candidates.end());
        for (auto &&i : candidates)
        {
            if (target < i)
            {
                break;
            }

            backtrack(candidates, target, i);
        }
        for (auto &&l : tempRes)
        {
            res.push_back(std::move(l));
        }

        return res;
    }

    void backtrack(vector<int> &candidates, int target, int num)
    {
        thisSum += num;
        thisList.push_back(num);
        if (thisSum == target)
        {
            vector<int> resList(thisList);
            sort(resList.begin(), resList.end());
            tempRes.insert(resList);
        }
        else if (thisSum < target)
        {
            for (auto &&i : candidates)
            {
                if (target < thisSum + i)
                {
                    break;
                }

                backtrack(candidates, target, i);
            }
        }

        thisSum -= num;
        thisList.pop_back();
    }
};