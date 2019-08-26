import java.util.Stack;

/*
 * @Author: SourDumplings
 * @Date: 2019-08-26 11:35:33
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode.com/problems/implement-queue-using-stacks/
 * 
 * s1负责push，s2负责Pop，在连续Pop时做到近似O(1)，Push为O(n)
 * peek时所做的调整和pop一样
 */

class MyQueue
{
    private Stack<Integer> s1 = null;
    private Stack<Integer> s2 = null;

    /** Initialize your data structure here. */
    public MyQueue()
    {
        s1 = new Stack<Integer>();
        s2 = new Stack<Integer>();
    }

    /** Push element x to the back of queue. */
    public void push(int x)
    {
        s1.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    public int pop()
    {
        if (s2.isEmpty())
        {
            while (!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
        }

        return s2.pop();
    }

    /** Get the front element. */
    public int peek()
    {
        if (s2.isEmpty())
        {
            while (!s1.isEmpty())
            {
                s2.push(s1.pop());
            }
        }
        return s2.peek();
    }

    /** Returns whether the queue is empty. */
    public boolean empty()
    {
        return s1.isEmpty() && s2.isEmpty();
    }
}

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * boolean param_4 = obj.empty();
 */