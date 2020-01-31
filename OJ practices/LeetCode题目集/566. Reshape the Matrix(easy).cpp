/*
 * @Author: SourDumplings
 * @Date: 2019-10-05 16:08:40
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/reshape-the-matrix/
 */

class Solution
{
private:
    int ir = 0, ic = 0;

public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c)
    {
        if (nums.empty())
        {
            return nums;
        }
        int nr = nums.size();
        int nc = nums[0].size();
        if (nr * nc != r * c)
        {
            return nums;
        }
        vector<vector<int>> res;
        res.resize(r);
        for (int i = 0; i < r; i++)
        {
            res[i].resize(c);
            for (int j = 0; j < c; j++)
            {
                res[i][j] = getNext(nums, nc);
            }
        }
        return res;
    }

    int getNext(vector<vector<int>> &nums, int nc)
    {
        if (ic == nc)
        {
            ++ir;
            ic = 0;
        }
        return nums[ir][ic++];
    }
};