/*
 * @Author: SourDumplings
 * @Date: 2021-01-21 09:33:43
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/peeking-iterator/
 */

class PeekingIterator: public Iterator
{
private:
    queue<int> q;
public:
    PeekingIterator(const vector<int> &nums) : Iterator(nums)
    {
        // Initialize any member here.
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.

    }

    // Returns the next element in the iteration without advancing the iterator.
    int peek()
    {
        int res;
        if (q.empty())
        {
            res = Iterator::next();
            q.push(res);
        }
        else
        {
            res = q.front();
        }
        return res;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next()
    {
        int res;
        if (q.empty())
        {
            res = Iterator::next();
        }
        else
        {
            res = q.front();
            q.pop();
        }
        return res;
    }

    bool hasNext() const
    {
        return Iterator::hasNext() || !q.empty();
    }
};