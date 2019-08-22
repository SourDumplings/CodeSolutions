/*
 * @Author: SourDumplings
 * @Date: 2019-08-22 20:00:05
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/implement-stack-using-queues/
 * 
 * 就是每次push的时候先在队列2中加新元素，再把队列1中旧元素转移到队列2中，
 * 再交换指针（避免复制）即可
 * Push O(n)， Pop O(1)
 */

class MyStack
{
private:
    queue<int> q1, q2;

public:
    /** Initialize your data structure here. */
    MyStack()
    {
    }

    /** Push element x onto stack. */
    void push(int x)
    {
        q2.push(x);
        while (!q1.empty())
        {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop()
    {
        int res = q1.front();
        q1.pop();
        return res;
    }

    /** Get the top element. */
    int top()
    {
        return q1.front();
    }

    /** Returns whether the stack is empty. */
    bool empty()
    {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
