/*
 * @Author: SourDumplings
 * @Date: 2021-01-08 12:11:20
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/majority-element-ii/
 * 
 * 参考：https://leetcode-cn.com/problems/majority-element-ii/solution/liang-fu-dong-hua-yan-shi-mo-er-tou-piao-fa-zui-zh/
 */

class Solution
{
public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> res;
        if (n > 0)
        {
            pair<int, int> p1, p2;
            p1 = make_pair(nums[0], 1);
            p2 = make_pair(0, -1);
            for (int i = 1; i < n; ++i)
            {
                if (nums[i] == p1.first)
                {
                    ++p1.second;
                }
                else
                {
                    if (p2.second == -1)
                    {
                        p2.first = nums[i];
                        p2.second = 1;
                    }
                    else if (nums[i] == p2.first)
                    {
                        ++p2.second;
                    }
                    else
                    {
                        if (p1.second == 0)
                        {
                            p1.first = nums[i];
                            p1.second = 1;
                        }
                        else if (p2.second == 0)
                        {
                            p2.first = nums[i];
                            p2.second = 1;
                        }
                        else
                        {
                            --p1.second;
                            --p2.second;
                        }
                    }
                }
            }
            int c1 = 0, c2 = 0;
            for (int j = 0; j < n; ++j)
            {
                if (nums[j] == p1.first)
                {
                    ++c1;
                }
                else if (nums[j] == p2.first)
                {
                    ++c2;
                }
            }
            if (c1 > n / 3)
            {
                res.push_back(p1.first);
            }
            if (c2 > n / 3)
            {
                res.push_back(p2.first);
            }
        }
        return res;
    }
};
