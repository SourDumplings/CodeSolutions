/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 * @Date: 2019-04-17 22:37:25
 */

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int n = numbers.size();
        vector<int> ret(2);
        for (int i = 0; i < n - 1; i++)
        {
            int thisTarget = target - numbers[i];
            for (int j = i + 1; j < n; j++)
            {
                if (numbers[j] == thisTarget)
                {
                    ret[0] = i + 1;
                    ret[1] = j + 1;
                    return ret;
                }
                else if (numbers[j] > thisTarget)
                {
                    break;
                }
            }
        }
        return ret;
    }
};