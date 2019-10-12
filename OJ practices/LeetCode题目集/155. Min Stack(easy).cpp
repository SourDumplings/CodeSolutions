/*
 * @Author: SourDumplings
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/min-stack/
 * @Date: 2019-04-16 16:33:35
 */

class MinStack
{
    stack<int> s;
    map<int, int> nums;

  public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        s.push(x);
        ++nums[x];
    }

    void pop()
    {
        if (nums.find(s.top()) != nums.end())
        {
            --nums[s.top()];
            if (nums[s.top()] == 0)
            {
                nums.erase(s.top());
            }
        }

        s.pop();
    }

    int top()
    {
        return s.top();
    }

    int getMin()
    {
        return nums.begin()->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */