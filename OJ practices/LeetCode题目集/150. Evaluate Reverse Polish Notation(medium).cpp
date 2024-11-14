/**
 * @file 150. Evaluate Reverse Polish Notation(medium).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief https://leetcode.cn/problems/evaluate-reverse-polish-notation/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-14
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 */

class Solution
{
public:
	int evalRPN(vector<string> &tokens)
	{
		stack<int> S;
		for (const string &token : tokens)
		{
			if (isdigit(token.back()))
			{
				S.push(stoi(token));
				continue;
			}

			int num1 = S.top();
			S.pop();
			int num2 = S.top();
			S.pop();
			switch (token[0])
			{
				case '+': S.push(num2 + num1); break;
				case '-': S.push(num2 - num1); break;
				case '*': S.push(num2 * num1); break;
				case '/': S.push(num2 / num1); break;

				default: break;
			}
		}
		return S.top();
	}
};