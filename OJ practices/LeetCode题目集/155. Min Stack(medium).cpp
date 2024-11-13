/**
 * @file 155. Min Stack(medium).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief https://leetcode.cn/problems/min-stack/description/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-13
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 * 使用一个辅助栈，记录每个元素作为栈顶时最小值即可
 */

class MinStack
{
public:
	MinStack() {}

	void push(int val)
	{
		m_S.push(val);
		if (m_minVals.empty() || val < m_minVals.top()) { m_minVals.push(val); }
		else { m_minVals.push(m_minVals.top()); }
	}

	void pop()
	{
		m_S.pop();
		m_minVals.pop();
	}

	int top() { return m_S.top(); }

	int getMin() { return m_minVals.top(); }

private:
	stack<int> m_S;
	stack<int> m_minVals;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */