/*
 * @Author: SourDumplings
 * @Date: 2021-02-24 17:09:24
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/range-sum-query-mutable/
 * 
 * 参考：https://leetcode-cn.com/problems/range-sum-query-mutable/solution/qu-yu-he-jian-suo-shu-zu-ke-xiu-gai-by-leetcode/
 * 线段树是一种非常灵活的数据结构，它可以用于解决多种范围查询问题，
 * 比如在对数时间内从数组中找到最小值、最大值、总和、最大公约数、最小公倍数等
 */

class NumArray
{
private:
    int n;
    int *tree;

    void buildTree(vector<int> &nums)
    {
        for (int i = n, j = 0; i < 2 * n; ++i, ++j)
        {
            // n 个叶结点记录数值
            tree[i] = nums[j];
        }

        for (int i = n - 1; i > 0; --i)
        {
            // n - 1 个内部结点记录子节点的和
            tree[i] = tree[i * 2] + tree[i * 2 + 1];
        }
    }
public:
    NumArray(vector<int> &nums)
    {
        n = nums.size();

        if (n > 0)
        {
            tree = new int[n * 2];
            buildTree(nums);
        }
    }

    void update(int index, int val)
    {
        index += n;
        tree[index] = val;
        while (index > 0)
        {
            int l = index;
            int r = index;
            if (index % 2 == 0)
            {
                r = index + 1;
            }
            else
            {
                l = index - 1;
            }
            // 父节点更新
            tree[index / 2] = tree[l] + tree[r];
            index /= 2;
        }
    }

    int sumRange(int left, int right)
    {
        // 定位到对应叶结点的索引
        left += n;
        right += n;
        int sum = 0;
        while (left <= right)
        {
            if (left % 2 == 1)
            {
                sum += tree[left];
                ++left;
            }
            if (right % 2 == 0)
            {
                sum += tree[right];
                --right;
            }
            left /= 2;
            right /= 2;
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */