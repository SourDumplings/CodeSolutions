/*
 * @Autor: SourDumplings
 * @Date: 2019-10-23 07:40:16
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/kth-largest-element-in-a-stream/
 */
class KthLargest
{
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;

public:
    KthLargest(int k, vector<int> &nums)
    {
        int n = nums.size();
        this->k = k;
        if (n > 0)
        {
            sort(nums.begin(), nums.end());
            for (int i = n - 1; i >= 0 && i >= n - k; i--)
            {
                pq.push(nums[i]);
            }
        }
    }

    int add(int val)
    {
        if (pq.size() < k)
        {
            pq.push(val);
        }
        else if (pq.size() == k && val > pq.top())
        {
            pq.pop();
            pq.push(val);
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */