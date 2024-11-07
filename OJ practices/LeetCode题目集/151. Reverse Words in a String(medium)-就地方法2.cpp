/**
 * @brief https://leetcode.cn/problems/reverse-words-in-a-string/?envType=study-plan-v2&envId=top-interview-150
 * 
 */

class Solution
{
public:
	string reverseWords(string s)
	{
		int l = 0, r = 0;
		int n = s.length();
		reverseWord(s, 0, n);
		while (l < n)
		{
			while (r < n && s[r] != ' ')
			{
				++r;
			}
			reverseWord(s, l, r);
			while (r < n && s[r] == ' ')
			{
				++r;
			}
			l = r;
		}

		bool head = true;
		int i	  = 0;
		for (int j = 0; j < n; ++j)
		{
			char c = s[j];
			if (c == ' ')
			{
				if (head) { continue; }
				else if (s[j - 1] != ' ') { s[i++] = s[j]; }
			}
			else
			{
				head   = false;
				s[i++] = s[j];
			}
		}

		if (s[i - 1] == ' ') { --i; }

		return s.substr(0, i);
	}

private:
	void reverseWord(string &s, int l, int r)
	{
		for (int i = l; i < (l + r) / 2; ++i)
		{
			char temp		   = s[i];
			s[i]			   = s[r - (i - l) - 1];
			s[r - (i - l) - 1] = temp;
		}
	}
};