/*
 * @Author: SourDumplings
 * @Date: 2021-02-24 19:06:30
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/range-sum-query-mutable/
 */

class NumArray
{
private:
    int n;
    int *tree;
    vector<int> &numsV;

    void add(int index, int num)
    {
        for (; index <= n; index += index & -index)
        {
            tree[index] += num;
        }
    }

    int sum(int index)
    {
        int res = 0;
        for (; index > 0; index -= index & -index)
        {
            res += tree[index];
        }
        return res;
    }

    void buildTree()
    {
        fill(tree, tree + n + 1, 0);
        for (int i = 0; i < n; ++i)
        {
            add(i + 1, numsV[i]);
        }
    }
public:
    NumArray(vector<int> &nums) : numsV(nums)
    {
        n = nums.size();

        if (n > 0)
        {
            tree = new int[n + 1];
            buildTree();
        }
    }

    void update(int index, int val)
    {
        add(index + 1, val - numsV[index]);
        numsV[index] = val;
    }

    int sumRange(int left, int right)
    {
        return sum(right + 1) - sum(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */