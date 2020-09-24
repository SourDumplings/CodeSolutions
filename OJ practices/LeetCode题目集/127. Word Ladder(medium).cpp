/*
 * @Author: SourDumplings
 * @Date: 2020-09-24 10:01:14
 * @Link: https://github.com/SourDumplings/
 * @Email: changzheng300@foxmail.com
 * @Description: https://leetcode-cn.com/problems/word-ladder/
 */

class Solution
{
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        int n = wordList.size();
        bool checked[n];
        fill(checked, checked + n, false);
        int level = 1;
        lth = beginWord.length();
        for (int i = 0; i != n; ++i)
        {
            string &word = wordList[i];
            for (int j = 0; j != lth; ++j)
            {
                string
                    newWord = word.substr(0, j) + "." + word.substr(j + 1, lth);
                if (d.find(newWord) == d.end())
                {
                    d[newWord] = vector<int>();
                }
                d[newWord].push_back(i);
            }
        }
        queue<int> q;
        for (int i = 0; i != lth; ++i)
        {
            string newWord =
                beginWord.substr(0, i) + "." + beginWord.substr(i + 1, lth);
            if (d.find(newWord) != d.end())
            {
                for (int adIndex : d[newWord])
                {
                    q.push(adIndex);
                }
            }
        }
        while (!q.empty())
        {
            ++level;
            unordered_set<int> nextLevel;
            while (!q.empty())
            {
                int adIndex = q.front();
                q.pop();
                checked[adIndex] = true;
                string &adWord = wordList[adIndex];
                if (adWord == endWord)
                {
                    return level;
                }
                for (int i = 0; i < lth; ++i)
                {
                    string nextAdWord = adWord.substr(0, i) + "." + adWord.substr(i + 1, lth);
                    for (int nextIndex : d[nextAdWord])
                    {
                        if (!checked[nextIndex])
                        {
                            nextLevel.insert(nextIndex);
                        }
                    }
                }
            }
            for (int nextLevelIndex : nextLevel)
            {
                q.push(nextLevelIndex);
            }
        }
        return 0;
    }

private:
    unordered_map<string, vector<int>> d;
    int lth;
};