/*
 * @Author: SourDumplings 
 * @Date: 2019-09-09 23:04:39 
 * @Last Modified by: SourDumplings
 * @Last Modified time: 2019-09-09 23:04:59
 */

class NumArray
{
private:
    static const int MAXN = 10000;
    int res[MAXN][MAXN];

public:
    NumArray(vector<int> &nums)
    {
        int l = nums.size();
        for (int i = 0; i < l; i++)
        {
            res[i][i] = nums[i];
            for (int j = i + 1; j < l; j++)
            {
                res[i][j] = res[i][j - 1] + nums[j];
            }
        }
    }

    int sumRange(int i, int j)
    {
        return res[i][j];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */