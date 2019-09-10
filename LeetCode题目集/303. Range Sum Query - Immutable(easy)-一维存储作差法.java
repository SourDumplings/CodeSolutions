/*
 * @Author: SourDumplings 
 * @Date: 2019-09-10 08:25:00 
 * @Last Modified by: SourDumplings
 * @Last Modified time: 2019-09-10 08:27:49
 */
class NumArray
{
    private int[] res;

    public NumArray(int[] nums)
    {
        int l = nums.length;
        res = new int[l];
        if (l > 0)
        {
            res[0] = nums[0];
        }
        for (int i = 1; i < l; i++)
        {
            res[i] = res[i - 1] + nums[i];
        }
    }

    public int sumRange(int i, int j)
    {
        if (i == 0)
        {
            return res[j];
        }
        else
            return res[j] - res[i - 1];
    }
}

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */