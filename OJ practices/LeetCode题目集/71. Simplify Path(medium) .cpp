/**
 * @file 71. Simplify Path(medium) .cpp
 * @author SourDumplings (sourdumplings@qq.com)
 * @brief https://leetcode.cn/problems/simplify-path/?envType=study-plan-v2&envId=top-interview-150
 * @version 1.0.0
 * @date 2024-11-13
 *
 * @copyright Copyright (c) 2024 SourDumplings
 *
 */

class Solution
{
public:
	string simplifyPath(string path)
	{
		path += "/";
		vector<string> splitPaths;
		int l = path.length();
		string pathWord;
		for (int i = 0; i < l; ++i)
		{
			char c = path.at(i);
			if (c == '/')
			{
				if (pathWord.empty()) { continue; }
				else if (pathWord == ".") { pathWord.clear(); }
				else if (pathWord == "..")
				{
					if (!splitPaths.empty()) { splitPaths.pop_back(); }
					pathWord.clear();
				}
				else
				{
					splitPaths.push_back(pathWord);
					pathWord.clear();
				}
			}
			else { pathWord += c; }
		}

		if (splitPaths.empty()) { return "/"; }

		string res;
		for (const string &eachPathWord : splitPaths)
		{
			res += "/" + eachPathWord;
		}
		return res;
	}
};
