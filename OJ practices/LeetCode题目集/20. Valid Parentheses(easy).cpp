/**
 * @file 20. Valid Parentheses(easy).cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief https://leetcode.cn/problems/valid-parentheses/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-13
 * 
 * @copyright Copyright (c) 2024 SourDumplings
 * 
 */

class Solution
{
public:
	bool isValid(string s)
	{
		stack<char> S;
		for (char c : s)
		{
			switch (c)
			{
				case '(':
				case '[':
				case '{':
				{
					S.push(c);
					break;
				}
				case ')':
				{
					if (S.empty() || S.top() != '(') { return false; }
					S.pop();
					break;
				}
				case ']':
				{
					if (S.empty() || S.top() != '[') { return false; }
					S.pop();
					break;
				}
				case '}':
				{
					if (S.empty() || S.top() != '{') { return false; }
					S.pop();
					break;
				}

				default: break;
			}
		}
		return S.empty();
	}
};