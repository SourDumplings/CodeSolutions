import java.util.Queue;

/*
 * @Author: SourDumplings
 * @Date: 2019-08-22 20:35:52
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/implement-stack-using-queues/
 * 
 * 两个队列q1和q2，在pop的时候先把q1中的所有元素pop-push到q2中（只留一个）
 * 然后交换q1和q2（避免复制）
 * push O(1)    pop O(n)
 */

class MyStack
{

    private Queue<Integer> q1 = null;
    private Queue<Integer> q2 = null;
    private Queue<Integer> temp = null;
    int top = 0;

    /** Initialize your data structure here. */
    public MyStack()
    {
        q1 = new LinkedList<Integer>();
        q2 = new LinkedList<Integer>();
    }

    /** Push element x onto stack. */
    public void push(int x)
    {
        q1.add(x);
        top = x;
    }

    /** Removes the element on top of the stack and returns that element. */
    public int pop()
    {
        while (q1.size() > 1)
        {
            q2.add(top = q1.remove());
        }
        int res = q1.remove();
        temp = q1;
        q1 = q2;
        q2 = temp;
        return res;
    }

    /** Get the top element. */
    public int top()
    {
        return top;
    }

    /** Returns whether the stack is empty. */
    public boolean empty()
    {
        return q1.isEmpty();
    }
}

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * boolean param_4 = obj.empty();
 */