/*
 * @Author: SourDumplings
 * @Date: 2019-08-26 10:51:01
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/implement-queue-using-stacks/
 * 
 * 利用两个栈，每次Push的时候调整，不然peek不好实现，Push O(1)  Pop O(n)，利用交换避免复制
 * 调整方法：每次push一个元素前把s1中元素导入到s2中再push元素到s1，再把s2中元素覆盖回s1即可
 */

class MyQueue
{
private:
    stack<int> s1, s2;

public:
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        while (!s1.empty())
        {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty())
        {
            s1.push(s2.top());
            s2.pop();
        }
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        int res = s1.top();
        s1.pop();
        return res;
    }

    /** Get the front element. */
    int peek()
    {
        return s1.top();
    }

    /** Returns whether the queue is empty. */
    bool empty()
    {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
